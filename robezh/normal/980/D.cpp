#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int num[5050], res[5050], sqr[10050];
int last[5050];
bool p[10050];
vector<int> prime;

int main(){
    for(int i = 0; i <= 10000; i++) sqr[i] = i*i;

    scanf("%d", &n);

    fill(p,p+10050,true);
    for(int i = 2; i <= 10000; i++)
        if(p[i]) for(int j = 2 * i; j <= 10000; j += i) p[j] = false;
    for(int i = 2; i <= 10000; i++){if(p[i]) prime.push_back(i);}

    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
        if(num[i] == 0) continue;
        for(int j : prime){
            while(num[i] % sqr[j] == 0) num[i] /= sqr[j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = i-1; j >= 1; j--){
            if(num[i] == num[j]){
                last[i] = j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        int cur = 0;
        for(int j = i; j <= n; j++){
            if(num[j] != 0 && last[j] < i) cur ++;
            res[max(1, cur)] ++;
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d ", res[i]);
    }
}