import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Random;

public class Main {
    private static FastScanner sc = new FastScanner();
    private static boolean DEBUG_FLG = false;

    public static void main(String[] args) {
    	int n = sc.nextInt();
    	Str[] s = new Str[n];
    	for(int i=0; i<n; i++) {
    		String str = sc.next();
    		char lastvow = '0';
    		int vownum = 0;
    		for(int j=0; j<str.length(); j++) {
    			if(str.charAt(j) == 'a' || str.charAt(j) == 'e' || str.charAt(j) == 'i' || str.charAt(j) == 'o' || str.charAt(j) == 'u') {
    				vownum++;
    				lastvow = str.charAt(j);
    			}
    		}
    		int lastvownum = 0;
    		if(lastvow == 'a') {
    			lastvownum = 1;
    		} else if(lastvow == 'e') {
    			lastvownum = 2;
    		} else if(lastvow == 'i') {
    			lastvownum = 3;
    		} else if(lastvow == 'o') {
    			lastvownum = 4;
    		} else if(lastvow == 'u') {
    			lastvownum = 5;
    		}
    		s[i] = new Str(str, vownum, lastvownum);
    	}
    	shuffleArray(s);
    	Arrays.sort(s, (a, b) -> a.vownum == b.vownum ? a.lastvow - b.lastvow : a.vownum - b.vownum);
    	ArrayList<Str> samelastvowpair = new ArrayList<>();
    	ArrayList<Str> notsamelastvowpair = new ArrayList<>();
    	Str tmp = null;
    	for(int i=0; i<n; i++) {
    		if(tmp == null) {
    			tmp = s[i];
    		} else {
    			if(s[i].vownum == tmp.vownum) {
    				if(s[i].lastvow == tmp.lastvow) {
        				samelastvowpair.add(tmp);
        				samelastvowpair.add(s[i]);
        				tmp = null;
        			} else {
        				if(i < n-1 && s[i].vownum == s[i+1].vownum && s[i].lastvow == s[i+1].lastvow) {
        					samelastvowpair.add(s[i]);
            				samelastvowpair.add(s[i+1]);
            				i++;
        				} else {
        					notsamelastvowpair.add(s[i]);
            				notsamelastvowpair.add(tmp);
            				tmp = null;
        				}
        			}
    			} else {
    				tmp = s[i];
    			}
    		}
    	}
    	int same = samelastvowpair.size() / 2;
    	int notsame = notsamelastvowpair.size() / 2;
    	while(same > notsame) {
    		same--;
    		notsame++;
    	}
    	String[][] ans = new String[same][4];
    	int sameidx = 0;
    	int notsameidx = 0;
    	for(int i=0; i<notsamelastvowpair.size() / 2; i++) {
    		if(same == 0) break;
    		ans[i][1] = samelastvowpair.get(sameidx).str;
    		sameidx++;
    		ans[i][3] = samelastvowpair.get(sameidx).str;
    		sameidx++;
    		ans[i][0] = notsamelastvowpair.get(notsameidx).str;
    		notsameidx++;
    		ans[i][2] = notsamelastvowpair.get(notsameidx).str;
    		notsameidx++;
    		same--;
    	}
    	for(int i=notsamelastvowpair.size() / 2; i<notsamelastvowpair.size() / 2 + same; i++) {
    		ans[i][1] = samelastvowpair.get(sameidx).str;
    		sameidx++;
    		ans[i][3] = samelastvowpair.get(sameidx).str;
    		sameidx++;
    		ans[i][0] =samelastvowpair.get(sameidx).str;
    		sameidx++;
    		ans[i][2] = samelastvowpair.get(sameidx).str;
    		sameidx++;
    	}
    	System.out.println(ans.length);
    	StringBuilder sb = new StringBuilder();
    	for(int i=0; i<ans.length; i++) {
    		sb.append(ans[i][0]);
    		sb.append(" ");
    		sb.append(ans[i][1]);
    		sb.append("\n");
    		sb.append(ans[i][2]);
    		sb.append(" ");
    		sb.append(ans[i][3]);
    		sb.append("\n");
    	}
    	System.out.print(sb);
    }

    static class Str {
    	String str;
    	int vownum;
    	int lastvow;
    	boolean used = false;
		public Str(String str, int vownum, int lastvow) {
			this.str = str;
			this.vownum = vownum;
			this.lastvow = lastvow;
		}
    }

    static void debug(long... args) {
    	if(!DEBUG_FLG) return;
    	boolean flg = false;
    	for(long s : args) {
    		if(flg) System.out.print(" ");
    		flg = true;
    		System.out.print(s);
    	}
    	System.out.println();
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if(ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch(IOException e) {
                    e.printStackTrace();
                }
                if(buflen <= 0) {
                    return false;
                }
            }
            return true;
        }
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int nextInt(){
            return Integer.parseInt(next());
        }
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }

    static void shuffleArray(Str[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            Str tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
}