#include<iostream>
# include <algorithm>
using namespace std;
int a[1000001];
int first[1000001];
int second[1000001];
struct m
{
    int a;
    int b;
};
m ans[1000000];
bool my(m a1,m b1)
{
    return a1.a<b1.a;
}
int score1[1000000];
int score2[1000000];
int main()
{
    int n;
    cin>>n;
    int a1=0,a2=0;
    for (int i=0;i<1000000;i++)
        first[i]=second[i]=1000000000;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]==1)
            a1++,first[a1]=i;
        else
            a2++,second[a2]=i;
        score1[i]=a1;
        score2[i]=a2;
    }
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        int x=0;
        int s1=0;
        int s2=0;
        int t=i;
        int num1=0;int num2=0;
        int s=0;
        int last=-1;
        while(1)
        {
            if (x>n)
                break;
            if (min(first[num1+t],second[num2+t])>n)
                break;
            if (first[num1+t]<second[num2+t])
            {
               x=first[num1+t];
               s1++;
               last=1;
               num1=score1[x];//
               num2=score2[x];//
            }
            else
            {
                x=second[num2+t];
                s2++;
                last=2;
                num1=score1[x];
                num2=score2[x];
            }
            if (x==n-1 && s1!=s2)
            {
                if (s1>s2 && last==2)
                    break;
                if (s2>s1 && last==1)
                    break;
                m d;
                d.a=max(s1,s2);
                d.b=t;
                ans[tot++]=d;
                break;
            }
        }
    }
    sort(ans,ans+tot,my);
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
        cout<<ans[i].a<<" "<<ans[i].b<<endl;

}