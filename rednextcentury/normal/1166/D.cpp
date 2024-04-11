#include <bits/stdc++.h>
using namespace std;
long long add[52];
long long co[501];
long long m;
bool solve(long long need,int len)
{
    for (int i=1;i<=len;i++)
        need-=add[len-i+1],co[i]=1;
    if (need<0)return 0;
    for (int i=1;i<=len;i++)
    {
        long long j = min(m-1,need/add[len-i+1]);
        need -= add[len-i+1]*j;
        co[i]+=j;
    }
    if (need==0)return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    add[1]=1;
    for (int i=2;i<=51;i++)
    {
        for (int j=1;j<i;j++)
            add[i]+=add[j];
    }
    int q;
    cin>>q;
    while(q--)
    {
        long long a,b;
        cin>>a>>b>>m;
        if (a==b) {
            cout << 1 << ' ' << a << endl;
            continue;
        }
        int ok=0;
        for (int i=1;i<=50;i++)
        {
            long long sum=add[i]*a;
            if (sum>=b)
                break;
            if (solve(b-sum,i-1))
            {
                ok=i;
                break;
            }
        }
        if (ok){
            cout<<ok;
            long long sum=a;
            cout<<' '<<a;
            for (int i=1;i<ok;i++){
                cout<<' '<<sum+co[i];
                sum=sum*2+co[i];
            }
            cout<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}