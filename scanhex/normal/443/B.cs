using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CF253
{
    class B
    {
        readonly int[] _bad = { ' ', '\r', '\n' };

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = Console.Read())) != -1)
            {
            }
            sb.Append((char)i);

            while (Array.IndexOf(_bad, (i = Console.Read())) == -1)
            {

                sb.Append((char)i);
            }
            return sb.ToString();
        }

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        void run()
        {

                    var s = NextToken();

            var n = s.Length;
            var k = NextInt();
            var max = 0;
            for (var beg = 0; beg < n; ++beg)
            {
                for (var len = 1; len <= (n + k) >> 1; ++len)
                {
                    var equals = true;
                    for (var i = beg; i < Math.Min(beg + len, n); ++i)
                        if (i + len >= n + k || i + len < n && s[i] != s[i + len])
                            equals = false;
                    if (equals && len << 1 > max)
                        max = len << 1;
                }
            }
            Console.Write(Math.Max(max, (k >> 1) << 1));
        }
        static void Main(string[] args)
        {
            new B().run();
        }
    }
}