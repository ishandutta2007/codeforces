//In the name of God
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxn = 1e6 + 9;
int arr[Maxn],t[4 * Maxn],ans[Maxn];
int start[Maxn];
vector<int> op;
pair<int,int> do_query[4 * Maxn];
int L[Maxn],R[Maxn];
int n;
void update(int to_upd,int x,int v = 1,int b = 0,int e = n-1){
    int mid = b + e >> 1,l = v << 1,r = l | 1;
    if(b == e){
        t[v] = x;
        return;
    }
    if(mid + 1 > to_upd)
        update(to_upd,x,l,b,mid);
    else
        update(to_upd,x,r,mid+1,e);
    t[v] = t[l] + t[r];
    return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
    if(i > e || j < b)
        return 0;
    if(i <= b && e <= j)
        return t[v];
    int mid = b + e >> 1,l = v << 1,r = l | 1;
    return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
int main(){
    ios_base::sync_with_stdio(0);
    string S;
    cin >> S;
    n = S.size();
    int len = 0;
    int cur = 0;
    for(int i = 0; i < n;i++){
        if(S[i] == '(')
            op.push_back(i);
        else if(S[i] == ')' && !op.size())
            arr[i] = -1;
        else if(S[i] == ')'){
            start[cur] = op[op.size()-1];
            arr[i] = cur++;
            do_query[len++] = make_pair(i,op[op.size()-1] - Maxn);
            op.pop_back();
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m;i++){
        cin >> L[i] >> R[i];
        --L[i],--R[i];
        do_query[len++] = make_pair(R[i],i);
    }
    sort(do_query,do_query+len);
    for(int i = 0; i < len;i++){
        int pos = do_query[i].second;
        if(pos < 0){
    //      cerr << "Update " << pos + Maxn << ' ' << do_query[i].first << endl;
        }else{
    //      cerr << "Query " << pos << ' ' << L[pos] << ' ' << R[pos] << endl;
        }
        if(pos < 0){
            pos += Maxn;
            update(pos,1);
        }else{
            ans[pos] = query(L[pos],R[pos]);
        }
    }
    for(int i = 0; i < m;i++)
        cout << ans[i] * 2 << "\n";
    return 0;
}