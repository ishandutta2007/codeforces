#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll a,b;
int n = 0;
ll psum[500050];
ll num[500050];

double aver(int i){
    ll sum = psum[i] + num[n-1];
    double ave = (double)sum / (i+2);
    return ave;
}

bool check(int i){
    ll sum = psum[i] + num[n-1];
    double ave = (double)sum / (i+2);
    return (ave >= (double)num[i]);
}

int main(){
    scanf("%d", &q);
    while(q--){
        scanf("%d", &a);
        if(a == 1){
            scanf("%d", &b);
            if(n == 0) psum[n] = b, num[n] = b, n++;
            else{psum[n] = psum[n-1] + b, num[n] = b, n++;}
        }
        else{
            int l = -1, r = n-1;
            while(l+1 < r){
                int mid = (l+r) / 2;
                if(check(mid)) l = mid;
                else r = mid;
            }
            //cout << "l = " << l << " ";
            if(l == -1) printf("%.8lf\n", 0);
            else printf("%.8lf\n", (double)num[n-1] - aver(l));
        }
    }
}