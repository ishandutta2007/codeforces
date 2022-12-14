# include<iostream>
# include<set>
#include <algorithm>
# include <map>
using namespace std;
map<string,int> m;
bool like[100][100];
int main()
{
    int aj[]={1,2,3,4,5,6,7};
    m["Anka"]=1;
    m["Cleo"]=2;
    m["Troll"]=3;
    m["Dracul"]=4;
    m["Snowy"]=5;
    m["Chapay"]=6;
    m["Hexadecimal"]=7;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string h,l,g;
        cin>>h>>l>>g;
        like[m[h]][m[g]]=1;
    }
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b)
        swap(a,b);
    if (b>c)
        swap(b,c);
    if (c<a)
        swap(c,a);
    if (a>b)
        swap(a,b);
    int ans2=2000000001;
    int ans1=0;
    int t1,t2,t3;
    for (int i=1;i<=7;i++)
    {
        for (int x=i;x<=7;x++)
        {
            if (i+x+x>7)
                continue;
            int z=7-i-x;
            if (max(max(a/i,b/x),c/z)-min(min(a/i,b/x),c/z)<ans2)
            {
                ans2=max(max(a/i,b/x),c/z)-min(min(a/i,b/x),c/z);
                t1=i,t2=x,t3=z;
            }
        }
    }
    for (int i=1;i<=7;i++)
    {
        for (int x=i;x<=7;x++)
        {
            if (i+x+x>7)
                continue;
            int z=7-i-x;
            if (max(max(a/i,b/x),c/z)-min(min(a/i,b/x),c/z)==ans2)
            {

                t1=i,t2=x,t3=z;

    while(next_permutation(aj,aj+7))
    {
        int kok=0;
        int now=0;
        for (int i=0;i<t1;i++)
        {
            for (int x=0;x<t1;x++)
            {
                if (like[aj[now+i]][aj[now+x]])
                    kok++;
            }
        }
        now=t1;
        for (int i=0;i<t2;i++)
        {
            for (int x=0;x<t2;x++)
            {
                if (like[aj[now+i]][aj[now+x]])
                    kok++;
            }
        }
        now=t2+t1;
        for (int i=0;i<t3;i++)
        {
            for (int x=0;x<t3;x++)
            {
                if (like[aj[now+i]][aj[now+x]])
                    kok++;
            }
        }
        ans1=max(ans1,kok);
    }
            }
        }
    }
    cout<<ans2<<" "<<ans1<<endl;
}