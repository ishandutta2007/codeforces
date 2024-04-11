using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Runtime.Remoting.Metadata.W3cXsd2001;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace CF253
{
    struct Card
    {
        public int Color, Num;

        public Card(int color, string num)
        {
            Color = color;
            Num = int.Parse(num) - 1;
        }
    }
    class C
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

        private void run()
        {
            var n = NextInt();
            var h = new Dictionary<char, int>();
            h.Add('R', 0);
            h.Add('G', 1);
            h.Add('B', 2);
            h.Add('Y', 3);
            h.Add('W', 4);
            var s = "";
            var pairs = Enumerable.Range(0, n).Select(x => new Card(h[(s = NextToken())[0]], s.Substring(1, 1))).ToArray();
            pairs = pairs.Distinct().ToArray();
            n = pairs.Length;
            var min = 239;
            for (var m1 = 0; m1 < 1 << 5; ++m1)
            {
                var num = Enumerable.Range(0, 5).Select(x => (m1 & (1 << x)) > 0).ToArray();
                for (var m2 = 0; m2 < 1 << 5; ++m2)
                {
                    var color = Enumerable.Range(0, 5).Select(x => (m2 & (1 << x)) > 0).ToArray();
                    var good = true;
                    for (var i = 0; i < n; ++i)
                        for (var j = 0; j < i; ++j)
                        {
                            var g = pairs[i].Color != pairs[j].Color && (color[pairs[i].Color] || color[pairs[j].Color]) ||
                                     pairs[i].Num != pairs[j].Num && (num[pairs[i].Num] || num[pairs[j].Num]);
                            if (!g)
                                good = false;
                        }
                    var sum = num.Sum(x => x ? 1 : 0) + color.Sum(x => x ? 1 : 0);
                    if (good && sum < min)
                        min = sum;
                }
            }
            Console.Write(min);
        }
        static void Main(string[] args)
        {
            new C().run();
        }
    }
}