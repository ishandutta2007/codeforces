#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 11;

deque<int> d[3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1;
    for (int i=1; i<=n; i++)
        d[s[i]-'a'].push_back(i);
    string res="";
    while (1)
    {
        vector<pair<int,int> > t;
        int len=-1,p=-1;
        for (int j=0; j<=2; j++)
            if (d[j].size()>0)
            {
                int r=d[j].back(),l=d[j].front();
                if (r-l+1>len)
                {
                    len=r-l+1;
                    p=j;
                }
            }
        if (len==-1) break;
        if (d[p].size()==1)
        {
            if (res.size()*2+1<n/2) {cout<<"IMPOSSIBLE"; return 0;}
            cout<<res;
            cout<<char(p+'a');
            reverse(res.begin(),res.end());
            cout<<res;
            return 0;
        } else
        {
            res+=char(p+'a');
            int x=d[p].front(),y=d[p].back();
            for (int j=0; j<=2; j++)
            {
                while (d[j].size()>0&&d[j].front()<=x)
                    d[j].pop_front();
                while (d[j].size()>0&&d[j].back()>=y)
                    d[j].pop_back();
            }
        }
    }
    if (res.size()*2<n/2) {cout<<"IMPOSSIBLE"; return 0;}
    cout<<res;
    reverse(res.begin(),res.end());
    cout<<res;
}

/**

cbacacacbcbababacbcb
12345678901234567890

1 4 6 8 10 17 19
2 9 11 13 15 18 20
3 5 7 12 14 16

1 - 19
2 - 20
3 - 16

**/