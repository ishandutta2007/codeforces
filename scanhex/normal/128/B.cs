using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CF
{
    class Substr : IComparable<Substr>
    {
        public int i, j;
        public Substr(int i, int j)
        {
            this.i = i;
            this.j = j;
        }
        static int CompareTo(int i1, int j1, int i2, int j2)
        {
            if (B128.Hash(i1, j1) == B128.Hash(i2, j2))
                return 0;
            if (j1 - i1 < j2 - i2 && B128.Hash(i1, j1) == B128.Hash(i2, i2 + j1 - i1))
                return -1;
            if (j2 - i2 < j1 - i1 && B128.Hash(i2, j2) == B128.Hash(i1, i1 + j2 - i2))
                return 1;
            int L = 0, R = Math.Min(j1 - i1, j2 - i2);
            while (R - L > 1)
            {
                int M = (R + L) / 2;
                if (B128.Hash(i1, i1 + M) == B128.Hash(i2, i2 + M))
                    L = M;
                else
                    R = M;
            }
            return B128.s[i1 + L].CompareTo(B128.s[i2 + L]);
        }
        public int CompareTo(Substr other)
        {
            var comp = CompareTo(i, j, other.i, other.j);
            if (comp == 0)
                return i.CompareTo(other.i);
            return comp;
        }
    }
    class B128
    {
        readonly int[] _bad = { ' ', '\r', '\n', -1 };
        TextReader sr = Console.In;//new StreamReader("input.txt");
        TextWriter sw = Console.Out;

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = sr.Read())) != -1) ;
            sb.Append((char)i);
            while (Array.IndexOf(_bad, (i = sr.Read())) == -1)
                sb.Append((char)i);
            return sb.ToString();
        }

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        public static long[] hash;
        static long[] pows;
        public static long p = 23917, r = (long) 1e9 + 7;

        public static long Hash(int L, int R)
        {
            return ((hash[R] - hash[L] * pows[R - L]) % r + r) % r;
        }

        void Init(string s)
        {
            hash = new long[s.Length + 1];
            pows = new long[s.Length + 1];
            hash[0] = 0;
            pows[0] = 1;
            for (int i = 1; i <= s.Length; ++i)
            {
                hash[i] = (hash[i - 1] * p + s[i - 1]) % r;
                pows[i] = (pows[i - 1] * p) % r; 
            }
        }

        public static string s;

        void run()
        {
            s = NextToken();
            int k = NextInt();
            Init(s);
            var ss = new SortedSet<Substr>();
            for (int i = 0; i < s.Length; ++i)
                ss.Add(new Substr(i, i + 1));
            if (k > s.Length * (s.Length - 1L) / 2 + s.Length)
            {
                sw.Write("No such line.");
                return;
            }
            for (int i = 0; i < k - 1; ++i)
            {
                Substr min = ss.Min;
                ss.Remove(min);
                if (min.j < s.Length)
                    ss.Add(new Substr(min.i, min.j + 1));
            }
            sw.Write(s.Substring(ss.Min.i, ss.Min.j - ss.Min.i));
        }

        static void Main(string[] args)
        {
            new B128().run();
        }
    }
}