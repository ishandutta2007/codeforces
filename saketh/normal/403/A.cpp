#include<iostream>
#include<vector>
using namespace std;

int T, N, P;

int main(){
    for(cin >> T; T; T--){
        cin >> N >> P;
        vector<pair<int, int> > p_edg;
        for(int a=0; a<N; a++)
            for(int b=a+1; b<N; b++){
                if(a+1 == b || a+2 == b || a==1 && b==N-1 
                   || a==0 && b==N-2 || a==0 && b==N-1)
                    cout << a + 1 << " " << b+1 << endl;
                else p_edg.push_back(make_pair(a+1, b+1));
            }
        for(int p=0; p<P; p++)
            cout << p_edg[p].first << " " << p_edg[p].second << endl;
    }
}