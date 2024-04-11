using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CF253
{
    class D
    {
        readonly int[] _bad = { ' ', '\r', '\n', -1 };

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
                sb.Append((char)i == '.' ? ',' : (char)i);
            }
            return sb.ToString();
        }

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        void run()
        {
            var n = NextInt();
            var a = Enumerable.Range(0, n).Select(x => double.Parse(NextToken())).ToArray();
            Array.Sort(a.Select(x => -x).ToArray(), a);
            var d1 = new double[n];
            var d2 = new double[n];
            for (var i = 0; i < n; ++i)
            {
                d1[i] = a[i];
                d2[i] = 1 - a[i];
                for (var j = 0; j < i; ++j)
                    if (d1[j] * (1 - a[i]) + d2[j] * a[i] > d1[i])
                    {
                        d1[i] = d1[j] * (1 - a[i]) + d2[j] * a[i];
                        d2[i] = d2[j] * (1 - a[i]);
                    }
            }
            Console.Write(d1.Max().ToString(CultureInfo.InvariantCulture));
        }
        static void Main(string[] args)
        {
            new D().run();
        }
    }
}