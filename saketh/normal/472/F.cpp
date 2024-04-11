#include <vector>
#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std;

vector<pair<int, int> > X_OUT, Y_OUT;

int N;
vector<int> X, Y;

void read(vector<int> &v){
    for(int i=0, t; i<N; i++){
        cin >> t;
        v.push_back(t);
    }
}

void swap_rows(int i, int j, vector<int> &v, vector<pair<int, int> > &r){
    if(i == j) return;
    r.push_back(make_pair(i, j));
    r.push_back(make_pair(j, i));
    r.push_back(make_pair(i, j));
    swap(v[i], v[j]);
}

void xor_rows(int i, int j, vector<int> &v, vector<pair<int, int> > &r){
    r.push_back(make_pair(i, j));
    v[i] ^= v[j];
}

int gauss(vector<int> &v, vector<pair<int, int> > &vr){
    int r = 0, n = v.size();

    for(int i=0; i<30; i++)
        for(int j=r; j<n; j++)
            if((v[j]>>i)&1){
                swap_rows(j, r, v, vr);
                
                for(int k=0; k<n; k++)
                    if(k!=r && (v[k]>>i)&1)
                        xor_rows(k, r, v, vr);

                r++;
                break;
            }

    return r;
}

void fail(){
    cout << -1 << endl;
    exit(0);
}

int main(){
    cin >> N;
    read(X);
    read(Y);

    int xr = gauss(X, X_OUT), yr = gauss(Y, Y_OUT);

    for(int i=0; i<xr; i++){
        int p=0;
        while(!((X[i]>>p)&1)) p++;

        for(int j=0; j<max(xr, yr); j++)
            if((((X[j]>>p)^(Y[j]>>p))&1))
                xor_rows(j, i, X, X_OUT);
    }

    for(int i=0; i<max(xr, yr); i++)
        if(X[i] != Y[i])
            fail();

    ios_base::sync_with_stdio(false);
    cout << X_OUT.size() + Y_OUT.size() << "\n";
    for(int i=0; i<X_OUT.size(); i++)
        cout << X_OUT[i].first+1 << " " << X_OUT[i].second+1 << "\n";
    for(int i=Y_OUT.size()-1; i>=0; i--)
        cout << Y_OUT[i].first+1 << " " << Y_OUT[i].second+1 << "\n";
    cout.flush();

    return 0;
}