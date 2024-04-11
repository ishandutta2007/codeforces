#include <iostream>
using namespace std;

const int MAXN = 100005;

int N, v[MAXN];
bool outer[MAXN], inner[MAXN];

int mult[MAXN];
int neg = 0;
int odd = 0;

void add(int idx){
    if(idx == N || idx == -1) return;
    int val = v[idx];
    
    int old = mult[val];
    if(old < 0){ if(old == -1) neg--;}
    else{
        if(old%2 == 0) odd++;
        else odd--;
    }
        
    mult[val]++;
}

void rem(int idx){
    if(idx == N || idx == -1) return;
    int val = v[idx];

    int old = mult[val];
    if(old <= 0){ if(old == 0) neg++; }
    else{
        if(old%2 == 0) odd++;
        else odd--;
    }
    
    mult[val]--;
}

bool can_do(){ return (odd <= 1) && (neg==0); }
int mirr(int idx){ return N-1-idx; }
bool in(int L, int R, int i){ return L<=i && i<=R; } 

void intro(int L, int R, int i){
    int j = mirr(i);
    if(in(L, R, j)){ if(i!=j) add(i); }
    else rem(j);
    add(i);
}

void excom(int L, int R, int i){
    int j = mirr(i);
    if(in(L, R, j)){ if(i!=j) rem(i); }
    else add(j);
    rem(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i=0; i<N; i++) cin >> v[i];

    outer[0] = true;
    for(int o=1; 2*o <= N; o++){
        outer[o] = outer[o-1];
        outer[o] &= v[o-1] == v[N-o];
    }

    inner[0] = true;
    for(int i=1; 2*i <= N; i++){
        inner[i] = inner[i-1];
        int j1 = (N%2) ? (N/2 - i) : (N/2 - i);
        int j2 = (N%2) ? (N/2 + i) : (N/2 + i-1); 
        inner[i] &= v[j1] == v[j2];
    }

    long long ans = 0;

    int R = N;
    for(int L = N-1; L >= 0; L--){
        intro(L, R, L);

        int in = (N%2) ? max(0, L-(N/2)-1) : max(0, L-(N/2));
        if(!inner[in]) continue;
        
        while(R > L){
            R--;
            
            int out = min(N-1-R, L);           
            if(!outer[out]){ R++; break; }

            if(R+1 < N) excom(L, R+1, R+1);

            if(!can_do()){
                if(R+1 < N) intro(L, R+1, R+1);
                R++;
                break;
            }
        }
        
        if(R<N){

            ans += N-R;
        }
    }

    cout << ans << endl;
    return 0;
}