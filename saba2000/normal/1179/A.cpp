#include<bits/stdc++.h>
using namespace std;
int a[100009]; int b[100009];
int l[100009],r[100009];
main(){
    int n,q;
    cin >> n >> q;
    deque<int> p;
    int M = 0;
    for(int i = 1; i<= n; i++){
        scanf("%d",&a[i]);
        p.push_front(a[i]);
        M =max(M, a[i]);
    }
    int i = 1;
    while(p.back() != M){
        l[i] = p.back(); p.pop_back();
        r[i] = p.back(); p.pop_back();
        p.push_back(max(l[i],r[i]));
        p.push_front(min(l[i],r[i]));
        i++;
    }
    p.pop_back();
    for(int j = 0; j < n-1; j++){
        b[j] = p.back();
        p.pop_back();
    }

    while(q--){
        long long m;
        scanf("%lld", &m);
        if(m < i) printf("%d %d\n", l[m], r[m]);
        else printf("%d %d\n", M, b[(m - i) % (n - 1)]);
    }
}