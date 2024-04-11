#include <bits/stdc++.h>
using namespace std;
map<int,int> mp[1000000];
vector<int> vec[1000000];
int main() {
    ios_base::sync_with_stdio(0);
    int m,n;
    cin>>m>>n;
    for (int i=0;i<m;i++)
    {
        int s;
        cin>>s;
        while(s--)
        {
            int x;
            cin>>x;
            mp[i][x]=1;
            vec[i].push_back(x);
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=i+1;j<m;j++)
        {
            bool disjoint = 1;
            for (auto x:vec[i])
            {
                if (mp[j].find(x)!=mp[j].end()){
                    disjoint = 0;
                    break;
                }
            }
            if (disjoint)
            {
                cout<<"impossible"<<endl;
                return 0;
            }
        }
    }
    cout<<"possible"<<endl;

}