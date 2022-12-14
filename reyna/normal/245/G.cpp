//In the name of God
#include <iostream>
#include <vector>
using namespace std;
const int Maxn = 10020;
short cf[Maxn][Maxn];
string names[Maxn];
vector<int> al[Maxn];
int m,n = 0;
int find(string name){
    for(int i = 0; i < n;i++)
        if(name == names[i])
            return i;
    names[n] = name;
    return n++;
}
int main(){
    cin >> m;
    for(int i = 0; i < m;i++){
        string un,vn;
        cin >> un >> vn;
        int u = find(un),v = find(vn);
        cf[u][v] = -1 ;
        cf[v][u] = -1;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j < al[i].size();j++){
            for(int k = j+1; k < al[i].size();k++){
                int u = al[i][j],v = al[i][k];
                if(cf[u][v]+1)
                    cf[u][v]++,cf[v][u]++;
            }
        }
    }
    cout << n << endl;
    for(int i = 0; i < n;i++){
        short Max = 0;
        for(int j = 0; j < n;j++){
            if(i - j)
                Max = max(Max,cf[i][j]);
        }
        int cnt = 0;
        for(int j = 0; j < n;j++)
            if(cf[i][j] == Max && cf[i][j] + 1 && i != j)
                cnt++;
        cout << names[i] << ' ' << cnt << endl;
    }
    return 0;
}