#include <bits/stdc++.h>
using namespace std;
set<int> S[1000];
char inp[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    scanf("%s",inp);
    s=inp;
    for (int i=0;i<s.size();i++) {
        S[s[i]-'a'].insert(i);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        if (t==2) {
            int l,r;
            scanf("%d%d",&l,&r);
            l--,r--;
            int num=0;
            for (int i=0;i<26;i++) {
                auto it = S[i].lower_bound(l);
                if (it!=S[i].end() && *it<=r)num++;
            }
            printf("%d\n",num);
        } else {
            int id;
            char x;
            scanf("%d %c",&id,&x);
            S[s[id-1]-'a'].erase(id-1);
            s[id-1]=x;
            S[x-'a'].insert(id-1);
        }
    }
}