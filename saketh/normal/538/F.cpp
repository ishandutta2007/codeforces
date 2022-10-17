#include <iostream>
using namespace std;

const int MAXN = 200005;

int N;
int heap[MAXN];
int viol[MAXN];

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> heap[i];

    for(int i=1; i<N; i++){   
            
        int md = 0;
        for(int d=1; d*d <= i; d++){
            md = d;
            if(heap[i] < heap[(i-1)/d]) {
                viol[d-1]++;
                viol[d]--;
            }
        }

        md++;

        for(int j=0; md*j+1<=i; j++){
            if(heap[j] <= heap[i]) continue;

            int large = j ? ((i-1)/j) : N;
            int small = max(md, (i+j)/(j+1));
            if(small > large) continue;

            viol[small-1]++;
            viol[large]--;                
        }
    } 

    int val = viol[0];
    for(int d=1; d<N; d++){
        cout << val << " ";
        val += viol[d];
    }
    cout << endl;
}