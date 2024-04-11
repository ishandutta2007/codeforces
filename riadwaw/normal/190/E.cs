using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
using System.Diagnostics;
using System.Globalization;

namespace CodeForces {
    struct Node {
        public int X, Y, D;        
        public Node(int x,int y, int d) {
            X = x;
            Y = y;
            D = d;
        }                
    }

    class Pair : IComparable<Pair> {
        public long First, Second;
        public Pair(int f, int s) {
            First = f;
            Second = s;
        }

        public int CompareTo(Pair other) {
            return Second.CompareTo(other.Second);
        }
    }

        
    class Cf {        
        static TextReader input;
        static void Main(string[] args) {            
#if TESTS            
            Stopwatch sw = new Stopwatch();
            sw.Start();
            input = new StreamReader("input.txt");            
#else
            input = Console.In;
#endif
            Solve();            
#if TESTS
            Console.WriteLine();
            Console.WriteLine("Milliseconds: {0}", sw.ElapsedMilliseconds);
            Console.ReadLine();
#endif
        }
        const int MOD = 1000000007;
        static int n, m, k;
        static bool[] u;       
        static HashSet<long> gr = new HashSet<long>();
        static void Solve() {
            n = nextInt();
            m = nextInt();            
            u = new bool[n];
            List<long> list = new List<long>(m << 1);
            next = new List<int>(Enumerable.Range(0, n));
            for (int i = 0; i < m; i++) {
                long x = nextInt() - 1;
                long y = nextInt() - 1;
                gr.Add(x*500000 + y);
                gr.Add(y*500000 + x);
            }
            //gr = new HashSet<long>(list);
            for (int i = 0; i < n; i++) {
                if (u[i]) continue;
                comp = new List<int>(n);
                bfs(i);
                ans.Add(comp);
            }
            Console.WriteLine(ans.Count);
            foreach (var item in ans) {
                Console.Write("{0} ", item.Count);
                foreach (int i in item) {
                    Console.Write("{0} ", i + 1);
                }
                Console.WriteLine();
            }
        }
        static List<int> comp, next, current;
        static List<List<int>> ans = new List<List<int>>();

        static void bfs(int i) {
            u[i] = true;
            comp.Add(i);
            Queue<int> q = new Queue<int>();
            q.Enqueue(i);
            while (q.Count > 0) {
                int v = q.Dequeue();
                current = next;
                next = new List<int>();
                foreach (int x in current) {
                    if (!u[x] && !gr.Contains((long)v * 500000 + x)) {
                        u[x] = true;
                        q.Enqueue(x);
                        comp.Add(x);
                    }
                    else
                        next.Add(x);
                }
            }
        }

        
        static int[] Z_function(string s) {
            int n = s.Length;
            int[] z = new int[n];            
            for (int i = 1, l = 0, r = 0; i < n; ++i) {
                if (i <= r)
                    z[i] = Math.Min(r - i + 1, z[i - l]);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                    ++z[i];
                if (i + z[i] - 1 > r) {
                    l = i; r = i + z[i] - 1;
                }
            }
            return z;
        }

        static int SquaredDistanceBetweenSegments(int x1, int y1, int x2, int y2, int xx1, int yy1, int xx2, int yy2) {
            return Math.Min(Math.Min(SquaredDistanceToSegment(x1, y1, xx1, yy1, xx2, yy2), SquaredDistanceToSegment(x2, y2, xx1, yy1, xx2, yy2)),
                Math.Min(SquaredDistanceToSegment(xx1, yy1, x1, y1, x2, y2), SquaredDistanceToSegment(xx2, yy2, x1, y1, x2, y2)));
        }

        static int SquaredDistanceToSegment(int x, int y, int x1, int y1, int x2, int y2) {
            int result = Math.Min(SquaredDistance(x, y, x1, y1), SquaredDistance(x, y, x2, y2));
            if (x1 == x2 && y1 <= y && y <= y2)
                result = (x - x1) * (x - x1);
            else if (y1 == y2 && x1 <= x && x <= x2)
                result = (y - y1) * (y - y1);
            return result;
        }

        static int SquaredDistance(int ax, int ay, int bx, int by) {
            return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        }

        #region read helpers
        static int nextInt() {
            int t = input.Read();
            while (t < '0' || t > '9') t = input.Read();
            int x = 0;
            while (t >= '0' && t <= '9') {
                x *= 10;
                x += t - '0';
                t = input.Read();
            }
            return x;
        }

        public static List<int> ReadIntList() {
            return input.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
        }

        public static int[] ReadIntArray() {            
            return input.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
        }

        public static long[] ReadLongArray() {
            return input.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
        }

        public static List<long> ReadLongList() {
            return input.ReadLine().Split(' ').Select(x => long.Parse(x)).ToList();
        }              

        public static string ReadLine() {
            return input.ReadLine();
        }

        public static int ReadInt() {
            return int.Parse(input.ReadLine());
        }
#endregion
    }
        
    public class SegmentTree {
        private int[] a, t;
        private int n;
        public SegmentTree(int[] a) {
            n = a.Length;
            this.a = a;            
            t = new int[n << 2];
            buildSegmentTree(0, n - 1, 1);
        }

        private void buildSegmentTree(int l, int r, int v) {
            if (l == r)
                t[v] = a[l];
            else {
                int m = (l + r) >> 1;
                int vl = v << 1;
                int vr = (v << 1) | 1;
                buildSegmentTree(l, m, vl);
                buildSegmentTree(m + 1, r, vr);
                t[v] = t[vl] + t[vr];
            }
        }

        public int QuerySegmentTree(int l, int r) {
            return querySegmentTree(1, l, r, 0, n - 1);
        }

        public void Update(int v, int tl, int tr, int pos, int new_val) {
            if (tl == tr)
                t[v] = new_val;
            else {
                int tm = (tl + tr) / 2;
                if (pos <= tm)
                    Update(v << 1, tl, tm, pos, new_val);
                else
                    Update(v << 1 + 1, tm + 1, tr, pos, new_val);
                t[v] = t[v << 1] + t[v << 1 + 1];
            }
        }

        private int querySegmentTree(int v, int l, int r, int tl, int tr) {
            if (l > r)
                return 0;
            if (l == tl && r == tr)
                return t[v];
            int m = (tl + tr) >> 1;                    
            return querySegmentTree(v << 1, l, Math.Min(r, m), tl, m) + querySegmentTree((v << 1) | 1, Math.Max(l, m + 1), r, m + 1, tr);
        }
    }
    class Graph : List<List<int>> {
        public Graph(int num): base(num) {
            for (int i = 0; i < num; i++) {
                this.Add(new List<int>());
            }
        }
    }

    class Heap<T> : IEnumerable<T> where T : IComparable<T> {
        private List<T> heap = new List<T>();
        private int heapSize;
        private int Parent(int index) {
            return (index - 1) >> 1;
        }
        public int Count {
            get { return heap.Count; }
        }
        private int Left(int index) {
            return (index << 1) | 1;
        }
        private int Right(int index) {
            return (index << 1) + 2;
        }
        private void Max_Heapify(int i) {
            int l = Left(i);
            int r = Right(i);
            int largest = i;
            if (l < heapSize && heap[l].CompareTo(heap[i]) > 0)
                largest = l;
            if (r < heapSize && heap[r].CompareTo(heap[largest]) > 0)
                largest = r;
            if (largest != i) {
                T temp = heap[largest];
                heap[largest] = heap[i];
                heap[i] = temp;
                Max_Heapify(largest);
            }
        }
        private void BuildMaxHeap() {
            for (int i = heap.Count >> 1; i >= 0; --i)
                Max_Heapify(i);
        }

        public IEnumerator<T> GetEnumerator() {
            return heap.GetEnumerator();
        }

        public void Sort() {
            for (int i = heap.Count - 1; i > 0; --i) {
                T temp = heap[i];
                heap[i] = heap[0];
                heap[0] = temp;
                --heapSize;
                Max_Heapify(0);
            }
        }

        public T Heap_Extract_Max() {
            T max = heap[0];
            heap[0] = heap[--heapSize];
            Max_Heapify(0);
            return max;
        }

        public void Clear() {
            heap.Clear();
            heapSize = 0;
        }

        public void Insert(T item) {
            if (heapSize < heap.Count)
                heap[heapSize] = item;
            else
                heap.Add(item);
            int i = heapSize;
            while (i > 0 && heap[Parent(i)].CompareTo(heap[i]) < 0) {
                T temp = heap[i];
                heap[i] = heap[Parent(i)];
                heap[Parent(i)] = temp;
                i = Parent(i);
            }
            ++heapSize;
        }

        IEnumerator IEnumerable.GetEnumerator() {
            return ((IEnumerable)heap).GetEnumerator();
        }
    }    
    public class Treap {
        private static Random rand = new Random();
        public static Treap Merge(Treap l, Treap r) {
            if (l == null) return r;
            if (r == null) return l;
            Treap res;
            if (l.y > r.y) {
                Treap newR = Merge(l.right, r);
                res = new Treap(l.x, l.y, l.left, newR);
            }
            else {
                Treap newL = Merge(l, r.left);
                res = new Treap(r.x, r.y, newL, r.right);
            }            
            return res;
        }

        public void Split(int x, out Treap l, out Treap r) {
            Treap newTree = null;
            if (this.x <= x) {
                if (right == null)
                    r = null;
                else
                    right.Split(x, out newTree, out r);
                l = new Treap(this.x, y, left, newTree);        
            }
            else {
                if (left == null)
                    l = null;
                else
                    left.Split(x, out l, out newTree);
                r = new Treap(this.x, y, newTree, right);                
            }
        }

        public Treap Add(int x) {
            Treap l, r;
            Split(x, out l, out r);
            Treap m = new Treap(x, rand.Next());
            return Merge(Merge(l, m), r);
        }

        public Treap Remove(int x) {
            Treap l, m, r;
            Split(x - 1, out l, out r);
            r.Split(x, out m, out r);
            return Merge(l, r);
        }

        private int x, y, cost, maxTreeCost;
        private Treap left, right;
        public Treap(int x, int y, Treap l, Treap r) {
            this.x = x;
            this.y = y;
            left = l;
            right = r;
        }
        public Treap(int x, int y) : this(x, y, null, null) { }
        public void InOrder() {
            inOrder(this);
        }
        private void inOrder(Treap t) {
            if (t == null) return;
            inOrder(t.left);
            Console.WriteLine(t.x);
            inOrder(t.right);
        }
    }
    public static class Extensions {
        public static void Fill(this int[] array, int val) {
            for (int i = 0; i < array.Length; i++) {
                array[i] = val;
            }
        }

        public static void Fill(this double[] array, double val) {
            for (int i = 0; i < array.Length; i++) {
                array[i] = val;
            }
        }

        public static int ToInt(this string s) {
            return int.Parse(s);
        }

        public static string Fill(this char c, int count) {
            char[] r = new char[count];
            for (int i = 0; i < count; ++i)
                r[i] = c;
            return new string(r);
        }
                        
        public static void Print<T>(this IEnumerable<T> arr) {
            foreach (T t in arr)
                Console.Write("{0} ", t);
        }
    }
}