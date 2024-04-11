#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 500;

int n,q,l,r,a,b,c;
bool rev = false;
int num[N], bit[N];

int get(int i){
    int ans = 0;
    while(i){ans += bit[i]; i -= (i&-i);}
    return ans;
}

int add(int i, int val){
    while(i < N){bit[i] += val; i += (i&-i);}
}

int main(){
    fill(bit, bit+N, 0);
    for(int i = 1; i < N; i++) add(i, 1);
    scanf("%d%d", &n, &q);
    l = 1, r = n+1;
    while(q--){
        scanf("%d", &a);
        if(a == 1){
            scanf("%d", &b);
            if(!rev){
                if(2 * b <= r - l){
                    for(int i = l; i < l + b; i++) add(2 * (l + b) - 1 - i, get(i) - (i == 0 ? 0 : get(i-1)));
                    l = l + b;
                }
                else{
                    for(int i = l + b; i < r; i++) add(2 * (l + b) - 1 - i, get(i) - (i == 0 ? 0 : get(i-1)));
                    rev = true;
                    r = l + b;
                }
            }
            else{
                if(2 * b <= r - l){
                    for(int i = r - b; i < r; i++) add(2 * (r - b) - 1 - i, get(i) - (i == 0 ? 0 : get(i-1)));
                    r = r - b;
                }
                else{
                    for(int i = l; i < r - b; i++) add(2 * (r - b) - 1 - i, get(i) - (i == 0 ? 0 : get(i-1)));
                    rev = false;
                    l = r - b;
                }
            }
        }
        else{
            scanf("%d%d", &b, &c);
            if(!rev) printf("%d\n", get(l + c - 1) - get(l + b - 1));
            else printf("%d\n", get(r - b - 1) - get(r - c - 1));
        }

//        for(int i = l; i < r; i++){
//            cout << get(i) - get(i-1) << " ";
//        }
//        cout << endl;
    }
}