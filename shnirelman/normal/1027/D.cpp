#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> used;
vector<int> c, a;

int INF = 100000;
int m, last, k = 0;

bool dfs(int v){
    last = v;
    used[v] = k;
    if(used[a[v]] == -1){
        dfs(a[v]);
    }
    else if(used[a[v]] == k)return true;
    else return false;
}

void dfs1(int v){
    used[v] = k;
    m = min(m, c[v]);
    if(used[a[v]] != k)dfs1(a[v]);
}

int main(){
    int n;
    cin >> n;

    vector<bool> b(n, false);
    a = c = used = vector<int>(n, -1);
    for(int i = 0; i < n; i++)cin >> c[i];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        if(a[i] != i)b[a[i]] = true;
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        if(used[i] == -1)
            /*if(a[i] == i){
                ans += c[i];
                k++;
                used[i] = k;
                k++;
            }
            else if(!b[i])*/{
                m = INF;
                k++;
                //cout << i << ' ' ;
                if(dfs(i)){
                    k++;
                    //cout << "rsj" << endl;
                    dfs1(last);
                    ans += m;

                }
            }

    cout << ans;
}