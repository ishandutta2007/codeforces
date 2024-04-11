#include <bits/stdc++.h>

#define sl ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){ sl

    long long x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    long long n;
    cin >> n;

    long long ans = 0;

    for(int i=0;i<n;i++){
        long a,b,c;
        cin >> a >> b >> c;
        if((a*x1 + b*y1 + c) > 0 && (a*x2 + b*y2 + c < 0))
            ans++;
        else if((a*x1 + b*y1 + c) < 0 && (a*x2 + b*y2 + c > 0))
            ans++;
    }
    cout<< ans;
    return 0 ;
}