#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 500;

int n;
int a[N], b[N];
bool have[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], have[a[i]] = true;
    for(int i = 0; i < n; i++) cin >> b[i];
    int ptr = 0;
    for(int i = 0; i < n; i++){
        if(have[b[i]]){
            int cnt = 0;
            while(ptr < n && a[ptr] != b[i]){
                have[a[ptr]] = false;
                ptr++, cnt++;
            }
            have[a[ptr++]] = false;
            cnt++;
            printf("%d ", cnt);
        }
        else{
            printf("0 ");
        }
    }

}