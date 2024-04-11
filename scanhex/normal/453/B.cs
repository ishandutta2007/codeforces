using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CF453
{
    class B
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

        void run()
        {
            var n = NextInt();
            int[] primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };
            var a = new int[n];
            var np = primes.Length;
            var masks = new int[61];
            for (int i1 = 1; i1 < 61; ++i1)
            {
                var msk = 0;
                var i = i1;
                for (var ind = 0; ind < np; ++ind)
                {
                    if (i % primes[ind] == 0)
                    {
                        msk |= 1 << ind;
                        while (i % primes[ind] == 0)
                            i /= primes[ind];
                    }
                }
                masks[i1] = msk;
            }
            for (var i = 0; i < n; ++i)
                a[i] = NextInt();
            var d = new int[n, 1 << np];
            var prev = new int[n, 1 << np];
            for (var i = 0; i < n; ++i)
                for (var j = 0; j < 1 << np; ++j)
                {
                    d[i, j] = int.MaxValue / 2;
                    prev[i, j] = -1;
                }
            for (var i = 1; i < 61; ++i)
            {
                var b = masks[i];
                if (d[0, b] > Math.Abs(i - a[0]))
                {
                    d[0, b] = Math.Abs(i - a[0]);
                    prev[0, b] = i;
                }
            }
            for (var pref = 0; pref < n - 1; ++pref)
            {
                for (var i = 1; i < 61; ++i)
                {
                    var b = masks[i];
                    var x = ((1 << 17) - 1) & (~b);
                    for (var mask = x; mask >= 0; mask = x & (mask - 1))
                    {
                        if ((b & mask) != 0)
                            continue;
                        var nmask = mask | b;
                        if (d[pref, mask] + Math.Abs(i - a[pref + 1]) < d[pref + 1, nmask])
                        {
                            d[pref + 1, nmask] = d[pref, mask] + Math.Abs(i - a[pref + 1]);
                            prev[pref + 1, nmask] = i;
                        }
                        if (mask == 0)
                            break;
                        //if (pref <= 2)
                        //sw.WriteLine(pref + 1 + " " + nmask + " " + d[pref + 1, nmask]);
                    }
                }
            }
            var ans = int.MaxValue / 2;
            var ind1 = -1;
            for (var mask = 0; mask < 1 << np; ++mask)
            {
                if (d[n - 1, mask] < ans)
                {
                    ans = d[n - 1, mask];
                    ind1 = mask;
                }
            }

            var arr = new List<int>();
            var i2 = n - 1;
            while (i2 >= 0)
            {
                arr.Add(prev[i2, ind1]);
                ind1 = ind1 ^ masks[prev[i2, ind1]];
                --i2;
            }
            arr.Reverse();
            foreach (var x in arr)
                sw.Write(x + " ");
            sr.ReadLine();
            sr.ReadLine();
        }

        static void Main(string[] args)
        {
            new B().run();
        }
    }
}