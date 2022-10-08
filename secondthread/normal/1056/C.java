import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		int nPlayers = 2 * fs.nextInt();
		int nPairs = fs.nextInt();
		Player[] players = new Player[nPlayers];
		for (int i = 0; i < nPlayers; i++)
			players[i] = new Player(i, fs.nextInt());
		Pair[] pairs = new Pair[nPairs];
		for (int i = 0; i < nPairs; i++) {
			int a = fs.nextInt() - 1, b = fs.nextInt() - 1;
			players[a].inPair = players[b].inPair = true;
			pairs[i] = new Pair(players[a], players[b]);
		}
		Player[] byPower = new Player[nPlayers];
		for (int i = 0; i < nPlayers; i++) {
			byPower[i] = players[i];
		}
		Arrays.sort(byPower);
		int t = fs.nextInt();
		if (t == 1) {
			for (int i = 0; i < nPairs; i++) {
				System.out.println((pairs[i].pickFirst() ? pairs[i].first.index : pairs[i].second.index) + 1);
				System.out.flush();
				fs.nextInt();
			}
			for (int i = nPlayers - 1; i >= 0; i--) {
				if (byPower[i].inPair) {
					continue;
				}
				System.out.println(byPower[i].index + 1);
				System.out.flush();
				players[fs.nextInt() - 1].inPair = true;
			}
		} else {
			ArrayList<Pair> validPairs = new ArrayList<>();
			for (Pair p : pairs)
				validPairs.add(p);
			ArrayList<Player> validPlayers = new ArrayList<>();
			for (Player p : players)
				if (find(validPairs, p.index)==null)
					validPlayers.add(p);
			Collections.sort(validPlayers);
			for (int i = 0; i < nPlayers / 2; i++) {
				int oChoice = fs.nextInt() - 1;
				Pair oPicked = find(validPairs, oChoice);
				if (oPicked == null) {
					if (validPlayers.contains(players[oChoice]))
						validPlayers.remove(players[oChoice]);
					if (validPairs.isEmpty()) {
						Player toRemove = validPlayers.get(validPlayers.size() - 1);
						System.out.println(toRemove.index + 1);
						System.out.flush();
						validPlayers.remove(toRemove);
					} else {
						Pair next = validPairs.get(0);
						validPairs.remove(next);
						System.out.println((next.pickFirst() ? next.first.index : next.second.index) + 1);
						System.out.flush();
					}
				} else {
					validPairs.remove(oPicked);
					System.out.println(oPicked.other(oChoice) + 1);
					System.out.flush();
				}
			}
		}
	}

	static Pair find(ArrayList<Pair> validPairs, int picked) {
		for (Pair p : validPairs) {
			if (p.contains(picked))
				return p;
		}

		return null;
	}

	static class Pair {
		Player first, second;
		boolean picked = false;

		public Pair(Player first, Player second) {
			this.first = first;
			this.second = second;
		}

		public boolean pickFirst() {
			return first.compareTo(second) >= 0;
		}

		public boolean contains(int index) {
			return first.index == index || second.index == index;
		}

		public int other(int index) {
			return first.index ^ second.index ^ index;
		}
	}

	static class Player implements Comparable<Player> {
		int index, power;
		boolean inPair = false;

		public Player(int index, int power) {
			this.index = index;
			this.power = power;
		}

		public int compareTo(Player o) {
			return Integer.compare(power, o.power);
		}
	}

}