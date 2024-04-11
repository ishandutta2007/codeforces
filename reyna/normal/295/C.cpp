//In the name of God
#include <iostream>
using namespace std;
int n,k;
const int Maxn = 60;
const int Mod = 1e9 + 7;
pair<pair<int,int> , bool > Que[Maxn * Maxn * 2];
int dis[Maxn][Maxn][2];
long long num[Maxn][Maxn][2];
bool vis[Maxn][Maxn][2];
long long C[Maxn][Maxn];
int begin,end;
int main(){
    cin >> n >> k;
    k /= 50;
    int one = 0,two = 0;
    for(int i = 0 ;i < n;i++){
        int w;
        cin >> w;
        one += 2-(w / 50);
        two += w/100;
    }
    // State : int int bool
    Que[0] = make_pair(make_pair(0,0),0);
    num[0][0][0] = 1;
    vis[0][0][0] = 1;
    end++;
    for(int i = 0; i <= max(one,two);i++){
        for(int j = 0; j <= i;j++){
            if(j == i || j == 0)
                C[i][j] = 1;
            else
                C[i][j] = (C[i-1][j] + C[i-1][j-1]) % Mod;
        }
    }
    while(begin != end){
        pair<pair<int,int> , bool> now = Que[begin++];
        int first,second;
        if(now.second){
            first = now.first.first;
            second = now.first.second;
        }else{
            first = one - now.first.first;
            second = two - now.first.second;
        }
        for(int One = 0; One <= first;One++){
            for(int Two = 0; Two <= second;Two++){
                if(One != 0 || Two != 0){
                    if(One + Two * 2 <= k){
                        if(now.second){
                            int u = now.first.first - One,v = now.first.second - Two;
                            bool w = 1 - now.second;
                            if(!vis[u][v][w]){
                                Que[end++] = make_pair(make_pair(u,v),w);
                                dis[u][v][w] = dis[u+One][v+Two][1-w] + 1;
                                vis[u][v][w] = true;
                                num[u][v][w] = ((num[u+One][v+Two][1-w] * C[first][One]) % Mod) * C[second][Two];
                                num[u][v][w] %= Mod;
                            }else{
                                if(dis[u][v][w] == dis[u+One][v+Two][1-w] + 1){
                                    cerr << "hi" << endl;
                                    num[u][v][w] += ((num[u+One][v+Two][1-w] * C[first][One]) % Mod) * C[second][Two];
                                    num[u][v][w] %= Mod;
                                }
                            }
                        }else{
                            int u = now.first.first + One,v = now.first.second + Two;
                            bool w = 1 - now.second;
                            if(!vis[u][v][w]){
                                Que[end++] = make_pair(make_pair(u,v),w);
                                dis[u][v][w] = dis[u-One][v-Two][1-w] + 1;
                                vis[u][v][w] = true;
                                num[u][v][w] = ((num[u-One][v-Two][1-w] * C[first][One]) % Mod) * C[second][Two];
                                num[u][v][w] %= Mod;
                            }else{
                                if(dis[u][v][w] == dis[u-One][v-Two][1-w] + 1){
                                    num[u][v][w] += ((num[u-One][v-Two][1-w] * C[first][One]) % Mod) * C[second][Two];
                                    num[u][v][w] %= Mod;
                                    cerr << "hi" << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(num[one][two][1]){
        cout << dis[one][two][1] << endl;
        cout << num[one][two][1] << endl;
    }else{
        cout << -1 << endl << 0 << endl;
    }
    return 0;
}