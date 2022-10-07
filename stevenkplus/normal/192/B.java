/* sup
 * lol not much
  alright let's have bad coding style and bad commenting style
 lol why would we want comments oh wait I see
  */
  
import java.util.*; //steven http://codeforces.com/problemset/problem/192/B
import java.io.*; // nick oh wait do we nto need this T_T w/e

public class Main { // steven, not sure if i'm doing my java right i forgot everything
  public static void main(String[] args) throws Exception { // nick do w/e just set up I/O
         BufferedReader r = new BufferedReader(new InputStreamReader(System.in)); //steven i think a PQ is enough
        int n = Integer.parseInt(r.readLine()); // nick uh isn't this just some dumb DP?
        int ans = 0; /*steven actually just sort the tiles, and iterate. check if any adjacent was rained out for each. do we need some kind of pair*/
        StringTokenizer st = new StringTokenizer(r.readLine()); /* Nick uh yeah darn I can code that separately while you do the stuff*/
        pair ar[] = new pair[n]; //wait we need to do line by line though
    // Nick wait so like line N must always come before line N+1?
        //steven yeah no inserting :(
        for(int i = 0; i < n; i++) { // Nick okay fine tahs' okay
            int next = Integer.parseInt(st.nextToken()); //steven
            ar[i] = new pair(next, i); // Nick so first token is time and second token is index I think this is okay
        } //k, we need  now Pair extends pair loll also a boolean[] to mark when stuff is rained out
        boolean[] used = new boolean[n]; // Nick 
        Arrays.sort(ar); //i think this is right
        for(int i = 0; i < n; i++) { // Nick note to self pair must implement Comparable<pair>
            pair p = ar[i]; //steven we can have int fi and int se for pair.        
            used[p.fi] = true; // nick so like this? oh wait this is wrong it should be se lol we can just swap haha
            if (p.fi - 1 >= 0 && used[p.fi - 1] || (p.fi + 1 < n && used[p.fi + 1])) {//steven,  doesn't matter yeah
                System.out.println(p.se); // nick wait aren't you missing like p.fi == 0 or p.fi == n-1
                int what; //steven i have p.fi - 1 >= 0, is that wrong?
                // nick but like if the first or last tile is out then that also works
            } else if (p.fi == 0 || p.fi == n - 1) { // steven good catch i didn't read the problem
                System.out.println(p.se); /* nick also we need to be careful because we can't print multiple times so you might want to consider adding an else clause and then doing continue so we can break out at the right time */
            } else continue; //it's fine just end now wait we need to uh return here.
        return; // nick like this?
        } // i think so
   } // nick  
  static class pair implements Comparable<pair> { //steven
       public int fi, se; // nick
         public   int compareTo(pair o) { //steven also need constructor 
              return se - o.se; // nick
            } //steven
       public pair(int a, int b) { // nick so like we need to swap, so b to fi and 
            fi = b; //steven i think this is right
            se = a; // nick yeah 
       } //steven now Pair extends pair
    } // nick lol        
  // static class Pair extends pair { //steven this is ugly hm
    //   public Pair(int a, int b) { super(a,b); } // Nick
    //} //steven        
} // Nick gogo submit?
            //steven submittied we got it wrong
            //need public class my bad
            //compile error darn
            //lol woops br vs r :\
            //and static class ah
            //and public int compareTo darnnn
            //runtime error now
            //how do you do oop
            //lol uh idk but I don't understand what this class load error is hm what happens if we switch the case
// nick lol added