#include <iostream>
#include <vector>
using namespace std;

int N, sieve[100005];
bool done[100005];

vector<int> sp;
vector<pair<int, int> > m;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    sieve[1] = -1;
    for(int p=2; p<=N; p++)
        if(sieve[p]) continue;
        else for(int q=p; q<=N; q+=p)
            sieve[q] = p;

    for(int p=3; 2*p<=N; p++){
        if(sieve[p] != p) continue;
        
        vector<int> mult;
        for(int q=p; q<=N; q+=p){
            if(q == p+p) continue;
            if(done[q]) continue;
            mult.push_back(q);
            done[q] = true;
        }

        if(mult.size() % 2){
            done[p+p] = true;
            mult.push_back(p+p);
        }

        for(int i=0; i+1 < mult.size(); i+=2)
            m.push_back(make_pair(mult[i], mult[i+1]));
    }

    for(int i=2; i<=N; i++)
        if(!done[i] && (i%2 == 0))
            sp.push_back(i);

    for(int i=0; i+1 < sp.size(); i+=2)
        m.push_back(make_pair(sp[i], sp[i+1]));

    cout << m.size() << endl;
    for(int i=0; i < m.size(); i++)
        cout << m[i].first << " " << m[i].second << "\n";

    cout.flush();
    return 0;
}