using System;
using System.IO;
using System.Text;
using System.Linq;

namespace ITMO_DP_Contest
{
    class C73
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
            var s = NextToken().ToCharArray().Select(x => x - 'a').ToList();
            var k = NextInt();
            var good = new int[256, 256];
            var n = NextInt();
            for (var i = 0; i < n; ++i)
                good[NextToken()[0] - 'a', NextToken()[0] - 'a'] = NextInt();
            var d = new int[s.Count + 1, k + 1, 27];
            for (var i = 0; i < s.Count + 1; ++i)
                for (var j = 0; j < k + 1; ++j)
                    for (var ch = 0; ch < 27; ++ch)
                        d[i, j, ch] = int.MinValue / 2;
            d[0, 0, 26] = 0;
            for (var i = 0; i < s.Count; ++i)
                for (var j = 0; j <= k; ++j)
                    for (var ch = 0; ch < 27; ++ch)
                    {
                        d[i + 1, j, s[i]] = Math.Max(d[i + 1, j, s[i]], d[i, j, ch] + good[ch, s[i]]);
                        for (var ch1 = 0; ch1 < 26 && j != k; ++ch1)
                        {
                            d[i + 1, j + 1, ch1] = Math.Max(d[i + 1, j + 1, ch1], d[i, j, ch] + good[ch, ch1]);
                        }
                    }
            var max = int.MinValue;
            for (int j = 0; j < k + 1; ++j)
                for (var ch = 0; ch < 26; ++ch)
                    if (d[s.Count, j, ch] > max)
                        max = d[s.Count, j, ch];
            sw.Write(max);
        }

        static void Main(string[] args)
        {
            new C73().run();
        }
    }
}