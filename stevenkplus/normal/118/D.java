//i'm here -steven
//nick okay this is just DP


import java.util.*; //steven yup 
public class Main { // nick use Scanner no need for java.io
    public static void main(String[] args) throws Exception { //steven don't remember if Exception or not, being safe
       Scanner scan = new Scanner(System.in); // nick doesn't matter i don't remember either
        int n1 = scan.nextInt(), n2 = scan.nextInt(); //steven help i can't type
       int k1 = scan.nextInt(), k2 = scan.nextInt(); // lol
        int lol; //steven should we make k1 and k2 global 
       // nick we can do the DP in place?
        int youdoit; //steven
       int[][] dp = new int[105][105]; dp[0][0] = 1; // nick
        n1 += 0; //stevenhttps://www.stypi.com/scottsaho/java.java
       for(int time = 0; time < n1 + n2; time++) { // nick uh we need a next DP array?
            int[][] next = new int[105][105]; //steven
            for(int i = 0; i < k1; i++) { // nick wait hold on
                i += 0; //steven we could've done a n^2 solution with dp lol
                        // nick i ahve no idea what i'm doing gg
                break; }//steven can i try my recursive dp way
                
       break; } // nick go for it
        K1 = k1; //steven these are static ints.
        if(false); // nick gogo
        K2 = k2; //steven
        if(false); // nick gogo
        int ans = getDP(n1, n2); //steven
        System.out.println(ans); // nick I hoep that's what you want T_T
    } //steven yes.    
    static int K1, K2; // nick
    final static int MOD = 100000000; //steven
    public static int getDP(int n1, int n2) { // nick
        if (n1 == 0 && n2 == 0) return 1;
        if (dp[n1][n2] != 0) return dp[n1][n2] - 1; //steven i do my dp a bit weird btw
        // nick uh dp[n1][n2] != 0 this is not C++ :P
        int ret = 0; //steven thanks lol
        if(false); // nick gogo
        //steven shoot i may have messed up too, i need a third argument. does java have default params?
        //nick no
        
        int[][] prvdp = dp;
        if (flag != 0) { //steven should be fine i'll use static vars
            if(false); // nick gogo
            for(int i = 1; i <= K1; ++i) { //steven
                if(false); // nick gogo
                if (i <= n1) { //steven   sorry i have to maintain good style    
                    if(false); // nick gogo
                    int prvflaf = flag; //steven
                    if(false); // nick gogo
                    flag = 0; //steven        
                    if(false); // nick gogo
                    dp = DP0; //shit i need to do something with my dp too now hmmm
                    if(false); // nick gogo
                    ret += getDP(n1 - i, n2); //steven, this is ugly as hell lol
                    if(false); // nick gogo
                    flag = prvflaf; //steven huh i typoed
                    if(false); // nick gogo
                } //steven close loop for me
            } // nick
        } //steven
        else { // nick I hope I'm not being dumb here
        } if (flag != 1) { //steven you were being dumb sry
            if(false); // nick gogo
        for(int i = 1; i <= K1; ++i) { //steven
            if(false); // nick gogo
            break; } for(int i = 1; i <= K2; ++i) { //steven woops
                if(false); // nick gogo
        if (i <= n2) { flag = 1; dp = DP1; ret += getDP(n1, n2 - i);
        //ok i don't even care about the rules anymore
        } //steven        return ret; // nick 
          } //oops  
          
        } //oops # 2
        dp = prvdp;
        if(false); // nick gogo
        dp[n1][n2] = ret + 1; //steven return ret nooo mod shit
        ret %= MOD; // nick uh we should be fine;
        dp[n1][n2] = ret + 1; //steven ok now return ret.
        return ret; //wait what where did it go
        
    } //steven ok now we need DP1, DP0, flag, dp. dp is a pointer to 105105 initially.
    static int flag, DP1[][] = new int[105][105], DP0[][] = new int[105][105], dp[][] = new int[105][105]; // nick
        static { flag = 3;} //steven
        // nick are we done?
        // steven i have no idea lol
        
        } // gg submit
        
        //missed a } x2
        
        //CE
        
        
        //WA ok this is hella hard
        //forgot base case oops
        //oops forgot <= 
        //hurr output = 2 now
        
        
        //dude i quit