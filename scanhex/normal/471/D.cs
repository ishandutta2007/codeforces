using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CF
{
    class D471
    {
        readonly int[] _bad = { ' ', '\r', '\n', -1 };
        TextReader sr = Console.In;
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

        int[] PrefixFunction(List<int> s)
        {
            int[] p = new int[s.Count];
            int j = 0;
            for (int i = 1; i < s.Count; ++i)
            {
                while (s[j] != s[i] && j != 0)
                    j = p[j - 1];
                if (s[j] == s[i])
                    ++j;
                p[i] = j;
            }
            return p;
        }

        void run()
        {
            int n = NextInt(), w = NextInt();
            int[] a = new int[n];
            int[] b = new int[w];
            for (int i = 0; i < n; ++i)
                a[i] = NextInt();
            for (int i = 0; i < w; ++i)
                b[i] = NextInt();
            var str = new List<int>();
            for (int i = 0; i < w - 1; ++i)
                str.Add(b[i + 1] - b[i]);
            str.Add(int.MaxValue);
            for (int i = 0; i < n - 1; ++i)
                str.Add(a[i + 1] - a[i]);
            var p = PrefixFunction(str);
            var cnt = 0;
            for (int i = 0; i < str.Count; ++i)
                if (p[i] == w - 1)
                    ++cnt;
            sw.Write(cnt);
        }

        static void Main(string[] args)
        {
            new D471().run();
        }
    }
}