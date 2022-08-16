
import java.util.Scanner;


public class PetyaLanguage
{
    static String[] gr = {"lios","liala","etr","etra","initis","inites"};

    static int getCode(String s)
    {
        for(int i=0;i<6;i++) if(s.endsWith(gr[i])) return i;
        return 111;
    }

    static void done()
    {
        System.out.println("NO");
        System.exit(0);
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine(), s = "";

        if(s.length()!=0) done();
        
        String[] sa = S.split("\\s+");
        if(getCode(sa[0])>5) done();
        if(sa.length==1){ System.out.println("YES"); System.exit(0); }
        int type = getCode(sa[0])/2, gender = getCode(sa[0])%2;
        if(type==2) done();
        int need = 0;
        if(type==1) need = 2;
        for(int i=1;i<sa.length;i++)
        {
            if(getCode(sa[i])>5) done();
            int ctype = getCode(sa[i])/2, cgender = getCode(sa[i])%2;
            if(cgender!=gender) done();
            if(need==0)
            {
                if(ctype==0) continue;
                else if(ctype==1){ need=2; continue; }
                else done();
            }
            else if(ctype!=need) done();
        }
        if(getCode(sa[sa.length-1])/2==0) done();
        System.out.println("YES");
        System.exit(0);
    }
}