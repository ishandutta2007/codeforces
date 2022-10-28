import java.io.*;
import java.util.*;

public class ManthanqC {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		char s[] = in.readString().toCharArray();

		Trie trie = new Trie();
		
		int m = in.nextInt();
		
		String t[] = new String[m];
		for(int i = 0; i < m; i++){
			t[i] = in.readString();
			trie.add(new StringBuilder(t[i].toLowerCase()).reverse().toString().toCharArray(), i);
		}
		
		int dp[] = new int[n + 1];
		
		for(int i = n - 1; i >= 0; i--){
			TrieNode curr = trie.root;
			dp[i] = -1;
			for(int j = i ; j < n; j++){
				if(curr.child[s[j] - 'a'] == null)
					break;
				curr = curr.child[s[j] - 'a'];
				if(curr.leaf >= 0 && dp[j + 1] != -1){
					dp[i] = curr.leaf;
					break;
				}
			}
		}
		
		for(int i = 0; i < n;){
			w.print(t[dp[i]] + " ");
			i += t[dp[i]].length();
		}
		
		w.println();
		
		w.close();
	}

	static public class Trie {

		TrieNode root;

		Trie() {
			root = new TrieNode();
		}

		public void add(char a[], int idx) {
			TrieNode curr = root;
			for (int i = 0; i < a.length; i++) {
				if (curr.child[a[i] - 'a'] == null)
					curr.child[a[i] - 'a'] = new TrieNode();
				curr = curr.child[a[i] - 'a'];
			}
			curr.leaf = idx;
		}

	}

	static public class TrieNode {
		int leaf;
		TrieNode child[];

		TrieNode() {
			leaf = -1;
			child = new TrieNode[26];
		}
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}