        #include<bits/stdc++.h>
                using namespace std;
                
                 struct LiChaoTree
    {
        typedef long long ftype;
        #define MX 1e18
        #define MAX_QUERY 1e9
        #define MIN_QUERY -1e9
        struct Line
        {
            ftype m,c;
            Line(ftype M,ftype C){m=M;c=C;}
            Line(){};
        };
        ftype f(Line l,  ftype x)
        {
            return l.m*x+l.c;
        }
        struct node
        {
            Line line;
            node* L = NULL;
            node* R = NULL;
            node(){}
            node(Line l) { line = l; }
        };
        node *root;
        void init() { root = NULL; }
        void Insert(Line nw, node* &v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
        {
            if (v==NULL)
            {
                v = new node(nw);
                return;
            }
            ftype mid = (l + r) / 2;
            bool LEFT = f(nw, l) < f(v->line, l);
            bool MID = f(nw, mid) < f(v->line, mid);
            bool RIGHT = f(nw, r) < f(v->line, r);
            if (LEFT && RIGHT)
                v->line = nw;
            if (LEFT == RIGHT)
                return;
            if(LEFT!=MID)
            {
                if (RIGHT) swap(v->line,nw);
                Insert(nw, v->L, l, mid);
            }
            else
            {
                if (LEFT) swap(v->line,nw);
                Insert(nw, v->R, mid+1, r);
            }
        }
        ftype Get(ftype x, node *v, ftype l=MIN_QUERY, ftype r=MAX_QUERY)
        {
            if (v==NULL)
                return MX;
            ftype mid = (l + r) / 2;
            if(x <= mid)
                return min(f(v->line, x), Get(x, v->L, l, mid));
            else
                return min(f(v->line, x), Get(x, v->R, mid+1, r));
        }
     
        void add_line(ftype m,ftype c)
        {
            Insert(Line(m,c),root);
        }
        ftype query(ftype x)
        {
            return Get(x,root);
        }
    };
                long long dp[1000000],a[1000000],b[1000000];
                 
                int main()
                {
                    int n;
                    scanf("%d",&n);
                    for (int i=0;i<n;i++)
                        scanf("%lld",&a[i]);
                    for (int i=0;i<n;i++)
                        scanf("%lld",&b[i]);
                    dp[0]=0;
                    LiChaoTree chd;chd.init();
                    chd.add_line(b[0],dp[0]);
                    for (int i=1;i<n;i++)
                    {
                        dp[i]=chd.query(a[i]);
                        chd.add_line(b[i],dp[i]);
                    }
                    cout<<dp[n-1]<<endl;
                }