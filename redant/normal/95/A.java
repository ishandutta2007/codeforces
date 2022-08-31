
import java.util.Scanner;


public class CF77D1A
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String[] words = new String[n];
        for(int i=0;i<n;i++)
        {
            words[i] = sc.nextLine().toLowerCase();
        }
        String orig = sc.nextLine(), lower = orig.toLowerCase();
        boolean[] can = new boolean[orig.length()];
        char ch = sc.nextLine().charAt(0);
        char[] ret = orig.toCharArray();
        for(String w : words)
        {
            int pos = 0;
            while(true)
            {
                int npos = lower.indexOf(w,pos);
                if(npos<0) break;
                for(int i=npos;i<npos+w.length();i++) can[i] = true;
                pos = npos + 1;
            }
        }

        char ch2 = 'a';
        if(Character.toLowerCase(ch)=='a') ch2 = 'b';

        for(int i=0;i<ret.length;i++)
        {
            if(!can[i]) continue;

            char ch1 = ch;

            if(Character.toLowerCase(ch)==Character.toLowerCase(ret[i])) ch1 = ch2;

            
            if('a'<=ret[i] && ret[i]<='z') ret[i] = Character.toLowerCase(ch1);
            else ret[i] = Character.toUpperCase(ch1);
        }
        System.out.println(new String(ret));
    }
}