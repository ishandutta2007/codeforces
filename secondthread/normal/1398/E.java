import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	static TreeSet<Spell> goodSpells=new TreeSet<>();
	static TreeSet<Spell> badSpells=new TreeSet<>();
	static TreeSet<Spell> included=new TreeSet<>();
	static TreeSet<Spell> excluded=new TreeSet<>();
	static long includedSum=0;
	static long allSum=0;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nQ=fs.nextInt();
		HashMap<Integer, ArrayDeque<Spell>> goodSpellsOfPower=new HashMap<>();
		HashMap<Integer, ArrayDeque<Spell>> badSpellsOfPower=new HashMap<>();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQ; qq++) {
			boolean good=fs.nextInt()==1;
			int value=fs.nextInt();
			if (value>0) {
				//add this
				Spell toCreate=new Spell(value, good);
				if (good) {
					if (!goodSpellsOfPower.containsKey(value)) goodSpellsOfPower.put(value, new ArrayDeque<>());
					goodSpellsOfPower.get(value).addLast(toCreate);
					
					add(toCreate);
					include(excluded.last());
				}
				else {
					if (!badSpellsOfPower.containsKey(value)) badSpellsOfPower.put(value, new ArrayDeque<>());
					badSpellsOfPower.get(value).addLast(toCreate);
					
					add(toCreate);
					if (!included.isEmpty() && !excluded.isEmpty()) {
						//consider trading
						Spell a=included.first(), b=excluded.last();
						if (a.compareTo(b)<0) {
							exclude(a);
							include(b);
						}
					}
				}
			}
			else {
				//remove it
				value*=-1;
				if (good) {
					Spell toRemove=goodSpellsOfPower.get(value).removeFirst();
					if (toRemove.included) exclude(toRemove);
					else exclude(included.first());
					remove(toRemove);
					//remove from goodSpells
					//if it was included, remove from included
					//otherwise, exclude worst thing in included
				}
				else {
					Spell toRemove=badSpellsOfPower.get(value).removeFirst();
					if (toRemove.included) {
						include(excluded.last());
						exclude(toRemove);
					}
					remove(toRemove);
					//remove from badSpells
					//if it was excluded, removeFromExcluded
					//if included, move one from excluded -> included
				}
			}
			
			long ans=allSum+includedSum;
			if (!goodSpells.isEmpty() && goodSpells.first().included) {
				ans-=goodSpells.first().value;
				if (!excluded.isEmpty()) {
					ans+=excluded.last().value;
				}
			}
			out.println(ans);
//			System.out.println(ans);
		}
		out.close();
	}
	
	static int gSpellId=0;
	
	static void include(Spell s) {
		if (included.contains(s)) throw null;
		included.add(s);
		excluded.remove(s);
		s.included=true;
		includedSum+=s.value;
	}
	
	static void exclude(Spell s) {
		if (excluded.contains(s)) {
			
			throw null;
		}
		included.remove(s);
		excluded.add(s);
		s.included=false;
		includedSum-=s.value;
	}
	
	static void add(Spell s) {
		excluded.add(s);
		allSum+=s.value;
		if (s.goodType) {
			goodSpells.add(s);
		}
		else {
			badSpells.add(s);
		}
	}
	
	static void remove(Spell s) {
		if (included.contains(s)) {
//			System.out.println("Trying to remove spell "+s.id+" value: "+s.value);
			throw null;
		}
		excluded.remove(s);
		allSum-=s.value;
		if (s.goodType)
			goodSpells.remove(s);
		else
			badSpells.remove(s);
	}
	
	static class Spell implements Comparable<Spell> {
		int value;
		int id;
		boolean included=false;
		boolean goodType;
		
		public Spell(int value, boolean goodType) {
			this.value=value;
			this.id=gSpellId++;
			this.goodType=goodType;
		}
		
		public int compareTo(Spell o) {
			if (value!=o.value) return Integer.compare(value, o.value);
			return Integer.compare(id, o.id);
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}