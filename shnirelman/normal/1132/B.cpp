#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    long long s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
       
    sort(a.begin(), a.end());
    
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        
        cout << s - a[n - b] << endl;
    }
}
/*
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    
    if(a != d) 
        cout << 0;
    else if(a == 0 && c != 0)
        cout << 0 ;
    else 
        cout << 1;

}*/