#include<bits/stdc++.h>
using namespace std;
map<pair<string,int> ,vector<pair<string,int> > >  v;
map<pair<string,int> , int > D;
set<string> S;
main()
{
    int n;
    cin >> n;
    string a; int b;
    cin >> a >> b;
    pair<string,int> X={a,b};
    for (int i = 0; i < n; i++)
    {
        string x;
        int y;
        if (i == 0)
            x=a,
            y=b;
        else
        cin >> x >> y;
        int d;
        pair<string,int> X={x,y};
        cin >> d;
        for (int i = 0; i < d; i++)
        {
            string z;
            int t;
            cin >> z >> t;
            v[X].push_back({z,t});
        }
    }
    vector<pair<string,int> > V;
    V.push_back({a,b});
    vector<pair<string,int> > ans;
    S.insert(a);
    for (int i = 1; i <= n; i++)
    {
        vector<pair<string,int> > w;
        for (int j = 0; j < V.size(); j++){
            for (int k = 0; k < v[V[j]].size(); k++){
                w.push_back(v[V[j]][k]);
            }
        }
        sort(w.begin(), w.end());
        V.clear();
        w.push_back({"",-1});
        for (int i = 0; i < w.size()-1; i++)
        {
            if(w[i].first == w[i+1].first)
                continue;
            if(S.find(w[i].first)!=S.end())
                continue;
            S.insert(w[i].first);
            ans.push_back(w[i]);
            V.push_back(w[i]);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first <<" "<<ans[i].second << endl;
}