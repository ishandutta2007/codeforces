#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> edg[100005];
bool init[100005];
bool goal[100005];

vector<int> flipped;

void calc(int loc, int par, int even, int odd, int depth){
    bool flip;
    if(depth % 2) flip = odd % 2;
    else flip = even % 2;
    
    bool change;
    if((init[loc] ^ flip) == goal[loc]) change = false;
    else change = true;
    
    int nodd = odd, neven = even;
    if(change && (depth % 2)) nodd++;
    if(change && !(depth % 2)) neven++;
    
    if(change) flipped.push_back(loc);
    
    for(int i=0; i<edg[loc].size(); i++)
        if(edg[loc][i] != par)
            calc(edg[loc][i], loc, neven, nodd, depth+1);
}

int main(){
    cin >> N;
    
    for(int i=0; i<N-1; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        edg[A].push_back(B);
        edg[B].push_back(A);
    }
    
    for(int i=0; i<N; i++)
        cin >> init[i];
    for(int i=0; i<N; i++)
        cin >> goal[i];
    
    flipped.clear();
    calc(0, -1, 0, 0, 0);
    
    cout << flipped.size() << endl;
    for(int i=0; i<flipped.size(); i++)
        cout << flipped[i]+1 << endl;
    return 0;
}