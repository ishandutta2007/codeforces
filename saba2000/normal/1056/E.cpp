#include<bits/stdc++.h>
using namespace std;

// suffixRank is table hold the rank of each string on each iteration
// suffixRank[i][j] denotes rank of jth suffix at ith iteration

int suffixRank[22][int(1E6+100)];

struct mysuple {
    int originalIndex;   // stores original index of suffix
    int firstHalf;       // store rank for first half of suffix
    int secondHalf;      // store rank for second half of suffix
};

int cmp(mysuple a, mysuple b) {
    if(a.firstHalf == b.firstHalf) return a.secondHalf < b.secondHalf;
    else return a.firstHalf < b.firstHalf;
}
string s,t;
bool eq(int a, int b, int l){
    for(int k = 19; k >= 0; k--){
        if((1<<k) <= l){
            if(suffixRank[k][a] != suffixRank[k][b]) return 0;
            a+= (1<<k);
            b+= (1<<k);
            l -= (1<<k);
        }
    }
    return 1;
}
bool ch(int x,int y){
    int p = 0, z, o;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') z = p;
        else o = p;
        if(s[i] == '0') p += x; else p += y;
    }
    p = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0'){
            if(!eq(z, p, x)) { return 0;}

        }
        else if(!eq(o, p, y)) {return 0;}
        if(s[i] == '0') p += x; else p += y;
    }
    if( x == y && eq(z, o, x)){ return 0;}
    return 1;
}
main(){
    cin >> s >> t;
    int m = t.size();
    int z = 0, o = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') z++;
        else o++;
    }


    int N = t.size();
    for(int i = 0; i < N; ++i)
        suffixRank[0][i] = t[i] - 'a';


    mysuple L[N];
    for(int cnt = 1, ttp = 1; cnt < N; cnt *= 2, ++ttp) {

        for(int i = 0; i < N; ++i) {
            L[i].firstHalf = suffixRank[ttp - 1][i];
            L[i].secondHalf = i + cnt < N ? suffixRank[ttp - 1][i + cnt] : -1;
            L[i].originalIndex = i;
        }
        sort(L, L + N, cmp);

        suffixRank[ttp][L[0].originalIndex] = 0;

        for(int i = 1, currRank = 0; i < N; ++i) {

            if(L[i - 1].firstHalf != L[i].firstHalf || L[i - 1].secondHalf != L[i].secondHalf)
                ++currRank;

            suffixRank[ttp][L[i].originalIndex] = currRank;
        }

    }





    int ans = 0;
    for(int x = 1; z * x < t.size(); x++){
        if((m - x * z) % o == 0){
            int y = (m - x * z) / o;
            ans += ch(x, y);
        }
    }
    cout<<ans<<endl;
}