
import java.util.*;


public class Soccer
{
    class Team implements Comparable<Team>
    {
        String name;
        int goals;
        int diff;
        int score;

        public Team(String name)
        {
            this.name =  name;
            goals=diff=score=0;
        }

        public int compareTo(Team t)
        {
            if(score!=t.score) return t.score-score;
            if(diff!=t.diff) return t.diff-diff;
            return t.goals-goals;
        }
    }

    void run()
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = n*(n-1)/2;
        HashMap<String,Team> map = new HashMap<String, Soccer.Team>();
        for(int i=0;i<n;i++)
        {
            String s = sc.next();
            map.put(s, new Team(s));
        }

        for(int i=0;i<m;i++)
        {
            String s = sc.next();
            String[] sa = s.split("-");
            Team t1 = map.get(sa[0]);
            Team t2 = map.get(sa[1]);
            sa = sc.next().split(":");
            int g1 = Integer.parseInt(sa[0]);
            int g2 = Integer.parseInt(sa[1]);
            t1.goals+=g1; t2.goals+=g2;
            t1.diff+=g1-g2; t2.diff+=g2-g1;
            if(g1!=g2){ if(g1>g2) t1.score+=3; else t2.score+=3; }
            else{ t1.score+=1; t2.score+=1; }
        }

        TreeSet<Team> order = new TreeSet<Team>();
        for(Team t : map.values()) order.add(t);

        TreeSet<String> ret = new TreeSet<String>();
        int i = 0;
        for(Team t:order)
        {
            if(i<n/2) ret.add(t.name);
            else break;
            i++;
        }

        for(String s:ret)
            System.out.println(s);
    }

    public static void main(String[] args)
    {
        new Soccer().run();
    }
}