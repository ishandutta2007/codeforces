#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int N = 200005;
typedef long long LL;
char s[N] , t[N];
int n , m , K;
int a[N] , b[N];
void work() {
    scanf("%s%s" , s , t);
    n = strlen(s);
    map<string , int> Hash;
    int num = 0;
    m = n;
    while (m % 2 == 0)
        m /= 2;
    K = n / m;
    for (int i = 0 , k = 0 ; i < K ; ++ i) {
        string s1 , s2;
        for (int j = 0 ; j < m ; ++ j , ++ k)
            s1 += s[k] , s2 += t[k];
        if (!Hash.count(s1))
            a[i] = Hash[s1] = num ++;
        else
            a[i] = Hash[s1];
        if (!Hash.count(s2))
            b[i] = Hash[s2] = num ++;
        else
            b[i] = Hash[s2];        
    }
    
    int len = K;
    while (len > 0) {
        vector< vector<int> > A , B;
        for (int i = 0 , k = 0 ; i < K /len; ++ i) {
            vector<int> aa , bb;
            for (int j = 0 ; j < len ; ++ j , ++ k) {
                aa.push_back(a[k]);
                bb.push_back(b[k]);                
            }
            sort(aa.begin() , aa.end());
            sort(bb.begin() , bb.end());            
            A.push_back(aa);
            B.push_back(bb);
        }
        sort(A.begin() , A.end());
        sort(B.begin() , B.end());            
        if (A != B) {
            puts("NO");
            return;
        }
        len >>= 1;
    }
    puts("YES");
}

int main() {
    work();
    return 0;
}