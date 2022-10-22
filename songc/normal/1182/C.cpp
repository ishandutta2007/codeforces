#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 2147483647
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
string W[101010];
int A[1010101];
int E[1010101];
int I[1010101];
int O[1010101];
int U[1010101];

deque<pii> FQ, SQ;
vector<pii> Fans, Sans;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        cin >> W[i];
        int cnt=0;
        char last=0;
        for (char ch : W[i]){
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') cnt++, last = ch;
        }
        if (last == 'a'){
            if (A[cnt]) {
                SQ.push_back(pii(i, A[cnt]));
                A[cnt] = 0;
            }
            else A[cnt] = i;
        }
        if (last == 'e'){
            if (E[cnt]) {
                SQ.push_back(pii(i, E[cnt]));
                E[cnt] = 0;
            }
            else E[cnt] = i;
        }
        if (last == 'i'){
            if (I[cnt]) {
                SQ.push_back(pii(i, I[cnt]));
                I[cnt] = 0;
            }
            else I[cnt] = i;
        }
        if (last == 'o'){
            if (O[cnt]) {
                SQ.push_back(pii(i, O[cnt]));
                O[cnt] = 0;
            }
            else O[cnt] = i;
        }
        if (last == 'u'){
            if (U[cnt]) {
                SQ.push_back(pii(i, U[cnt]));
                U[cnt] = 0;
            }
            else U[cnt] = i;
        }
    }
    for (int i=0; i<=1000000; i++){
        if (A[i] && E[i]){
            FQ.push_back(pii(A[i], E[i]));
            A[i] = E[i] = 0;
        }
        if (A[i] && I[i]){
            FQ.push_back(pii(A[i], I[i]));
            A[i] = I[i] = 0;
        }
        if (A[i] && O[i]){
            FQ.push_back(pii(A[i], O[i]));
            A[i] = O[i] = 0;
        }
        if (A[i] && U[i]){
            FQ.push_back(pii(A[i], U[i]));
            A[i] = U[i] = 0;
        }
        if (E[i] && I[i]){
            FQ.push_back(pii(E[i], I[i]));
            E[i] = I[i] = 0;
        }
        if (E[i] && O[i]){
            FQ.push_back(pii(E[i], O[i]));
            E[i] = O[i] = 0;
        }
        if (E[i] && U[i]){
            FQ.push_back(pii(E[i], U[i]));
            E[i] = U[i] = 0;
        }
        if (I[i] && O[i]){
            FQ.push_back(pii(I[i], O[i]));
            I[i] = O[i] = 0;
        }
        if (I[i] && U[i]){
            FQ.push_back(pii(I[i], U[i]));
            I[i] = U[i] = 0;
        }
        if (O[i] && U[i]){
            FQ.push_back(pii(O[i], U[i]));
            O[i] = U[i] = 0;
        }
    }
    while (!SQ.empty()){
        Sans.push_back(SQ.front());
        SQ.pop_front();
        if (!FQ.empty()){
            Fans.push_back(FQ.front());
            FQ.pop_front();
        }
        else if (!SQ.empty()){
            Fans.push_back(SQ.front());
            SQ.pop_front();
        }
    }
    printf("%d\n", (int)Fans.size());
    for (int i=0; i<(int)Fans.size(); i++){
        cout << W[Fans[i].first] << ' ' << W[Sans[i].first] << '\n';
        cout << W[Fans[i].second] << ' ' << W[Sans[i].second] << '\n';
    }
    return 0;
}