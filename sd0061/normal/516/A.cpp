#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 105;
int n , a[N];
char str[N];

int p[10][4];
int t[4];
void work() {
    int i , j;
    scanf("%d%s" , &n , str);
    for (i = 0 ; i < n ; ++ i) {
        a[i] = str[i] - '0';
    }
    for (i = 2 ; i <= 9 ; ++ i) {
        p[i][0] = i / 2 + i / 4 + i / 8;
        p[i][1] = i / 3 + i / 9;
        p[i][2] = i / 5;
        p[i][3] = i / 7;        
    }
    vector<int> res;
    for (i = 0 ; i < n ; ++ i) {
        if (a[i] == 2)
            res.push_back(2);
        if (a[i] == 3)
            res.push_back(3);
        if (a[i] == 4)
            res.push_back(3) , res.push_back(2) , res.push_back(2);
        if (a[i] == 5)
            res.push_back(5);
        if (a[i] == 6)
            res.push_back(5) , res.push_back(3);
        if (a[i] == 7)
            res.push_back(7);
        if (a[i] == 8) {
            res.push_back(7);
            res.push_back(2);
            res.push_back(2);
            res.push_back(2);            
        }
        if (a[i] == 9) {
            res.push_back(7);
            res.push_back(3);
            res.push_back(3);
            res.push_back(2);            
        }        
        
                
        
        
    }
    sort(res.begin() , res.end() , greater<int>());
    for (auto it : res)
        cout << it;
    
    
        
}

int main() {
    //freopen("1" , "r" , stdin);
    work();
    return 0;
}