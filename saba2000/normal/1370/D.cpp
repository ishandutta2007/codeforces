#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[200009],b[200009];
main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int lo = 1, hi = 1e9;
    while(lo < hi){
        int mid = (lo +hi)/2;
        for(int i = 1; i <= n; i++){
            if(a[i] <= mid) b[i] = 0;
            else b[i] = 1;
        }
        int M00 = 0, M01 = 0, M10 = 0, M11 = 0;
        for(int i = 1; i <= n; i++){
            if(b[i] == 0) M11++, i++;
        }
        for(int i = 2; i <= n - 1;i++){
            if(b[i] == 0) M00++, i++;
        }
        for(int i = 1; i <= n - 1; i++){
            if(b[i] == 0) M10++, i++;
        }
        for(int i = 2; i <= n;i++){
            if(b[i] == 0) M01++, i++;
        }
        if(k % 2 == 0 && (M10 >= k/2 || M01 >= k/2)) hi = mid;
        else if(k % 2 == 1 && (M11 >= (k+1)/2 || M00 >= k/2)) hi = mid;
        else lo = mid + 1;


    }
    cout<<lo<<endl;

}
/*
2*

*/