#include <iostream>
using namespace std;

// used to read in and store the input; s is the ant array
int N, M, s[100005];

/* we store the segment tree in the following array
 * the leaves correspond to entries in the ant array
 * N <= 100000, so we pick 2^17 > 10^5 for the number of leaves
 * the total size of the tree is then 2^18 - 1
 *
 * an entry of the tree is a pair of integers, the first being
 * the gcd of the range of array entries that the entry 
 * corresponds to, and the second being a count of the 
 * number of array entries in that range equal to the gcd
 */
pair<int, int> seg[1 << 18];

// compute gcd(a, b), using the Euclidean algorithm
int gcd(int a, int b){
    if(a < b) return gcd(b, a);
    if(!b) return a;
    return gcd(b, a%b);
}

// function to "add" two vertices of the tree
pair<int, int> add(pair<int, int> a, pair<int, int> b){
    int nv = gcd(a.first, b.first);                                         // the new gcd is the gcd of the two child gcd's
    int ct = ((a.first == nv)?a.second:0) + ((b.first == nv)?b.second:0);   // determine the number of elements equal to the gcd
    return make_pair(nv, ct);
}

/* "insertion" operator. we will insert the ants into the tree one by one
 * we call with idx = the ant's index, and val = its strength
 *
 * internally, loc is used to track the index of the segment tree we 
 * are interacting with. its interval is stored as [lo, hi]
 */
void ins(int idx, int val, int loc = 1, int lo = 0, int hi = (1<<17)-1){    // default arguments start us at the root
    if(idx < lo || idx > hi) return;                                        // if the index we are updating is outside this interval, do nothing
    if(lo == hi){
        seg[loc] = make_pair(val, 1);                                       // if we are at a leaf, just look at the ant's strength
        return;
    }

    int wid = (hi-lo+1)/2;
    ins(idx, val, 2*loc, lo, lo+wid-1);                                     // update the left child
    ins(idx, val, 2*loc+1, lo+wid, hi);                                     // update the right child
    seg[loc] = add(seg[2*loc], seg[2*loc+1]);                               // our value is the "sum" of the child values
}

/* query operator. we will use this to compute the answers
 * we call with the interval [a, b] we wish to query
 * 
 * more specifically, calling this function with arguments 
 * (a, b, loc, lo, hi), such that [lo, hi] is the interval
 * associated with vertex loc, always returns the "contribution"
 * of that interval to the answer for query [a, b]
 *
 */
pair<int, int> que(int a, int b, int loc = 1, int lo = 0, int hi = (1<<17)-1){
    if(b < lo || a > hi) return make_pair(0, 0);                            // if the query and this interval don't intersect, there is no contribution
    if(a <= lo && hi <= b) return seg[loc];                                 // if this interval is fully contained inside the query, contribute everything

    int wid = (hi-lo+1)/2;
    return add(que(a, b, 2*loc, lo, lo+wid-1),                              // otherwise, query both children, and the contribution is the sum of their contributions
               que(a, b, 2*loc+1, lo+wid, hi));
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){                                                 // read the ants
        cin >> s[i];
        seg[(1<<17) + i] = make_pair(s[i], 1);                              // fill the leaves
    }

    for(int i=(1<<17)-1; i>=1; i--)                                         // build the rest of the tree
        seg[i] = add(seg[2*i], seg[2*i+1]);

    cin >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        cout << ((b-a+1) - que(a-1, b-1).second) << "\n";                   // answer each query
    }

    cout.flush();
    return 0;
}