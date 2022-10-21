#include <bits/stdc++.h>
using namespace std;

#define MAXN 100050

string str;
int Z[MAXN];
vector<int> res;

void setZ(){
    int n = str.length();
    int L, R, k;

    Z[0] = n;
    L = R = 0;

    for(int i = 1; i < n; i++){
        if(i > R){
            L = R = i;
            while(R < n && str[R] == str[R-L]) R++;
            Z[i] = R-L;
            R--;
        }
        else{
            k = i-L;

            if(Z[k] < R-i+1){
                Z[i] = Z[k];
            }
            else{
                L = i;
                while(R < n && str[R] == str[R-L]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main(){
    getline(cin, str);
    setZ();

    for(int i = str.length()-1; i >= 0; i--){
        if(Z[i] + i == str.length()) res.push_back(Z[i]);
    }
    sort(Z, Z + str.length());

    //  for(int i = 0; i < str.length(); i++) cout << Z[i] << " ";
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
        cout << Z + str.length() - lower_bound(Z, Z + str.length(), res[i]) ;
        cout << endl;
    }
}