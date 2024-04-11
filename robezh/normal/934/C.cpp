#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<P> V;
int n;
int a[2005];
int l[2005], r[2005];


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) l[i] = 1, r[i] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j]) l[i] = max(l[i], l[j]+1);
        }
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = n-1; j > i; j--){
            if(a[i] <= a[j]) r[i] = max(r[i], r[j]+1);
        }
    }
    int res = 1;
//    for(int i = 0; i < n-1; i++){
//        cout << "i = " << i << ": " << l[i] << " " << r[i] << endl;
//    }
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++) res = max(l[i] + r[j], res);
    }
    cout << res;

}