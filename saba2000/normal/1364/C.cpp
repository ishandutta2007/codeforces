#include<bits/stdc++.h>
using namespace std;
int a[100009],b[100009];
main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = -1;
    }
    set<int> s;
    for(int i = 0; i < n; i++){
        int x = a[i];
        s.insert(-i-1);
        while(x < a[i+1]){
            b[-*s.begin()] = x;
            s.erase(s.begin());
            x++;
        }
    }
    for(int i =1; i <= n; i++)
        if(b[i] == -1) b[i] = n + 2;
    for(int i = 1; i <= n ;i++)
        cout<<b[i]<<" ";
    cout<<endl;

}
/*


*/