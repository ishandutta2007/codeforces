    #include <iostream>
    #include <vector>
    #include <set>
    #include <cstdio>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <map>

    using namespace std;

    #define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
    #define MP make_pair
    #define ALL(a) ((a).begin(),(a).end())
    #define PB push_back
    #define PII pair<int,int>

    typedef long long ll;
    typedef unsigned long long ull;

    int main(){
        int n,m=1,k,l;
        string s;
        cin>>s;

        if (s.length()==1) {cout<<1;return 0;}
        k=1;
        FOR(i,1,s.length())
        {
            if (s[i]==s[i-1]) k++;
            else {k=1;m++;}
            if (k>5) {k=1;m++;}
        }
        cout<<m;
        return 0;
    }