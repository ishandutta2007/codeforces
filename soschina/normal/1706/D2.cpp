#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 1;

int t, n, k, a[N];

struct node{
    int l, pos;
    node(int l, int pos) : l(l), pos(pos){}
};
vector<node> vec[N];

int main(){
    scanf("%d", &t);
    while(t--){
        for (int i = 0; i < N; i++)
            vector<node>().swap(vec[i]);
        scanf("%d%d", &n, &k);
        int mina = 1e5;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            mina = min(mina, a[i]);
            vec[a[i]].push_back(node(1, i));
        }
        int ans = 1e5;
        for (int i = N - 1; i >= 0; i--){
            if(i == 0){
                ans = 0;
                break;
            }
            ans = min(ans, i - mina);
            bool flag = true;
            for(node nd : vec[i]){
                int r = a[nd.pos] / (a[nd.pos] / nd.l) + 1;
                if(r > k){
                    flag = false;
                    break;
                }
                mina = min(mina, a[nd.pos] / r);
                vec[a[nd.pos] / r].push_back(node(r, nd.pos));
            }
            vector<node>().swap(vec[i]);
            if(!flag)
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}