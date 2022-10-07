#include<bits/stdc++.h>
using namespace std;
int f[200009];
int w[200009];
int d[200009];
vector<int> V[1009];
vector<int> a;
vector<vector<int> > ans;
bool bfs(int n, int x){
    queue<int> q;
    q.push(0); f[0] = 1;
    vector<int> v;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n;k ++)
                if(k > j && j > i && k - j == j - i)
                    v.push_back((1<<k)|(1<<i)|(1<<j));
    while(q.size()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v.size(); i++){
            int y = x^v[i];
            if(f[y] == 0){
                w[y] = x;
                f[y] = 1;
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    if(!f[x]) return 0;
    int cnt = 0 ;
    while(x > 0){
        int k = (x^w[x]);
        for(int i = 0; i < n; i++)
            if((1<<i) & k) V[cnt].push_back(i+1);
        x  = w[x];
        cnt++;
    }
    for(int i = 0; i < cnt; i++)
        ans.push_back(V[i]);
    return 1;
}
void ANS(int x, int y, int z){
    a[x - 1] ^= 1;
    a[y - 1] ^= 1;
    a[z - 1] ^= 1;
    ans.push_back({x,y,z});
}
main(){
    srand(time(NULL));
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
       cin >> a[i];
    }
    vector<vector<int> > v =
    {
       {2,3,4},
       {3,4,5},
       {1,3,5},
       {1,2,3},
       {0,2,4},
       {0,1,2},
    };
    while(a.size() > 13){
        vector<int> b;
        int m = a.size();
        int k = 0;
        for(int i = m - 6; i < m; i++){
            b.push_back(a[i]);
            if(a[i]) k++;
        }
        if(k == 6){
            ANS(m-5, m-4, m-3);
            ANS(m-2, m-1, m);
            while(!a.back() && a.size() > 13) a.pop_back();
            continue;
        }
        for(int i = 0; i < v.size(); i++){
            if(b[v[i][0]] && b[v[i][1]] && b[v[i][2]]){
                b[v[i][0]] = 0;
                b[v[i][1]] = 0;
                b[v[i][2]] = 0;
                ANS(v[i][0] + m - 5,
                    v[i][1] + m - 5,
                    v[i][2] + m - 5);
            }
        }
        for(int i = 0; i < 6; i++){
            for(int j = 2*i + 1; j < 6; j++)
                if(b[i] && b[j]){
                    b[i] = 0;
                    b[j] = 0;
                    ANS(2*i - j + m - 5,
                        i + m - 5,
                        j + m - 5);
            }
        }
        for(int i = 0; i < 6; i++){
            if(b[i]){
                ANS(i + m - 5, m - 6,  m - 7 - i);
            }
        }
        while(!a.back() && a.size() > 13) a.pop_back();
    }
    int A = 0;
    for(int i = 0; i < a.size(); i++)
        if(a[i] == 1) A|= (1<<i);
    if(!bfs(a.size(), A)){
        cout << "NO"<<endl;
        return 0;
    }
    cout << "YES"<<endl << ans.size()<<endl;
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i][0] <<" "<<ans[i][1] <<" "<<ans[i][2]<<endl;
    }

    return 0;
}
/*

###.##
*/