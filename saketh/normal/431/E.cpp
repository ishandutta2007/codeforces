#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N, Q;
long long vals[100005];
long long oper[100005][3];

vector<long long> allv;
map<long long, int> idx;
map<int, long long> rev;

int BIT_SIZE = 200005;
long long bit[200005];
int bit2[200005];

long long read(int k){    
    long long sum = 0;
    while(k > 0){
        sum += bit[k];
        k -= (k & -k);
    }
    return sum;
}

int read2(int k){    
    int sum = 0;
    while(k > 0){
        sum += bit2[k];
        k -= (k & -k);
    }
    return sum;
}

void update(int i, long long v){
    while(i <= BIT_SIZE){
        bit[i]+=v;
        i += (i & -i);
    }
}

void update2(int i, int v){
    while(i <= BIT_SIZE){
        bit2[i]+=v;
        i += (i & -i);
    }
}

int main(){
    //input
    cin >> N >> Q;
    for(int i=0; i<N; i++){
        cin >> vals[i];
        allv.push_back(vals[i]);
    }
    
    for(int j=0; j<Q; j++){
        cin >> oper[j][0];
        if(oper[j][0] == 1){
            cin >> oper[j][1] >> oper[j][2];
            oper[j][1]--;
            allv.push_back(oper[j][2]);
        }
        else cin >> oper[j][1];
    }
    
    //compress values
    sort(allv.begin(), allv.end());
    int cur = 1;
    for(int i=0; i<allv.size(); i++)
        if(!i || allv[i] != allv[i-1]){
            idx[allv[i]] = cur;
            rev[cur++] = allv[i];
        }
     
    //initialize bit entries       
    for(int i=0; i<N; i++){
        update(idx[vals[i]], vals[i]);
        update2(idx[vals[i]], 1);
    }
        
    for(int j=0; j<Q; j++){
        if(oper[j][0] == 1){
            //value update
            int i = oper[j][1];
            update(idx[vals[i]], -vals[i]);
            update2(idx[vals[i]], -1);
            vals[i] = oper[j][2];
            update(idx[vals[i]], vals[i]);
            update2(idx[vals[i]], 1);
        }
        else{
        
            //binary search on index of BIT to stop at
            long long water = oper[j][1];
            double best = 1e50;
            
            int low = 1, high = cur-1;
            while(low <= high){
                int mid = (low + high) / 2;
                
                int nbuck = read2(mid);
                long long sbuck = read(mid);
                double height = (sbuck + water + 0.0) / nbuck;
                
                if(height < rev[mid]){
                    best = min(best, (double) rev[mid]);
                    high = mid-1;
                }
                else{
                    best = min(best, height);
                    low = mid+1;
                }
            }
            
            cout << best << endl;
        }
    }
    
    return 0;
}