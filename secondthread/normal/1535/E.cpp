#include <bits/stdc++.h>
using namespace std;

int amounts[1000000];
int costs[1000000];

struct Splay {
    int node, best, size;
    Splay* par, *pathParent;
    Splay* kids[2];
    
    Splay(int data): node(data), best(data), size(1) {
        par=pathParent=kids[0]=kids[1]=NULL;
    }
    
    int indexOfKid(Splay *kid) {
        if (kids[0]==kid) return 0;
        if (kids[1]==kid) return 1;
        assert(0);
    }
};

int BETTER(int aa, int bb) {
    if (amounts[aa]==0) return bb;
    if (amounts[bb]==0) return aa;
    if (costs[aa]<costs[bb]) return aa;
    else return bb;
}

void recalc(Splay *x) {
    if (x==NULL) return;
    x->best=x->node;
    x->size=1;
    for (Splay *kid:x->kids) if (kid!=NULL) x->best=BETTER(x->best, kid->best);
    for (Splay *kid:x->kids) if (kid!=NULL) x->size+=kid->size;
}

//rotate edge x -> x.par
void rotate(Splay *x) {
    Splay *p=x -> par, *g=p->par;
    int onR=p->indexOfKid(x);
    Splay *toTrade=x->kids[onR^1];
    p->kids[onR]=toTrade; if (toTrade!=NULL) toTrade->par=p;
    x->kids[onR^1]=p; p->par=x;
    if (g!=NULL) g->kids[g->indexOfKid(p)]=x; x->par=g;
    x->pathParent=p->pathParent;
    p->pathParent=NULL;
    
    recalc(p);
    recalc(x);
}

//brings x to the root
void splay(Splay *x) {
    while (x->par!=NULL) {
        Splay *p=x->par, *g=p->par;
        if (g==NULL)
            rotate(x);
        else {
            if (g->indexOfKid(p)==p->indexOfKid(x)) {
                //zig-zig
                rotate(p);
                rotate(x);
            }
            else {
                //zig-zag
                rotate(x);
                rotate(x);
            }
        }
    }
}

//separates x from x.par
void behead(Splay *x) {
    Splay *p=x->par;
    int onR=p->indexOfKid(x);
    p->kids[onR]=x->par=NULL;
    recalc(p);
}

void addToSide(Splay *main, Splay *toAdd, int side) {
    splay(main);
    while (main->kids[side]!=NULL) main=main->kids[side];
    main->kids[side]=toAdd;
    toAdd->par=main;
    recalc(main);
}

void access(Splay *v) {
    splay(v);
    Splay *rightKid=v->kids[1];
    if (rightKid!=NULL) {
        behead(rightKid);
        rightKid->pathParent=v;
    }
    while (v->pathParent!=NULL) {
        Splay *w=v->pathParent;
        v->pathParent=NULL;
        //switch w's preferred child to v
        splay(w);
        Splay *prev=w->kids[1];
        if (prev!=NULL) {
            prev->pathParent=w;
            behead(prev);
        }
        addToSide(w, v, 1);
        splay(v);
    }
}

int pathAggregate(Splay *v) {
    access(v);
    return v->best;
}

void link(Splay *u, Splay *v) {
    v->pathParent=u;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int nQueries; cin>>nQueries;
    vector<Splay> splays;
    for (int i=0; i<=nQueries; i++) splays.emplace_back(i);
    cin>>amounts[0]>>costs[0];

    int totalLoops=0;
    for (int qq=1; qq<=nQueries; qq++) {
        int type; cin>>type;
        if (type==1) {
            int parent;
            cin>>parent>>amounts[qq]>>costs[qq];
            link(&splays[parent], &splays[qq]);
        }
        else {
            //TODO: process things
            // int node=fs.nextInt();
            // int amount=fs.nextInt();
            int node, amount; cin>>node>>amount;
            //repeatedly buy the cheapest until:`
            // - none left
            // - we buy all we need
            
            long long spent=0;
            int amountBought=0;
            while (amount>0) {
                int best=pathAggregate(&splays[node]);
                int amountToBuy=min(amounts[best], amount);
                if (amountToBuy==0)
                    break;
                totalLoops++;
                if (totalLoops>nQueries*3) {
                    assert(0);
                    return 0;
                }
                access(&splays[best]);
                amounts[best]-=amountToBuy;
                amountBought+=amountToBuy;
                amount-=amountToBuy;
                spent+=costs[best]*(long long)amountToBuy;
                recalc(&splays[best]);
                
            }
            cout<<amountBought<<" "<<spent<<endl;
        }
    }

    return 0;
}