#include<bits/stdc++.h>
using namespace std;

const int E26 = 1400000;

int n;
int num[100050];
int res[100050], prime[1400050];
bool used[1400050];

void elim(int t){
    while(t != 1) {
        int p = prime[t];
        used[p] = true;
        t /= p;
    }
}

bool good(int t){
    while(t != 1) {
        int p = prime[t];
        if (used[p]) return false;
        t /= p;
    }
    return true;
}

int main(){
    fill(used, used+E26+1, false);
    for(int i = 2; i <= E26; i++) prime[i] = i;
    for(int i = 2; i <= E26; i++){
        if(prime[i] != i) continue;
        for(int j = i*2; j <= E26; j+=i) prime[j] = i;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    int eq = 1;
    for(int i = 0; i < n; i++){
        if(eq != 1){
            int pos = 2;
            if(eq == 0){eq = -1;}
            else{pos = res[i-1] + 1;}
            while(used[pos] || !good(pos)) pos++;
            res[i] = pos;
        }
        else if(good(num[i])){
            res[i] = num[i];
        }
        else{
            int now = num[i]+1;
            while(used[now] || !good(now)) now++;
            res[i] = now;
            eq = 0;
        }
        elim(res[i]);
    }
    for(int i = 0; i < n; i++){
        printf("%d ", res[i]);
    }

}