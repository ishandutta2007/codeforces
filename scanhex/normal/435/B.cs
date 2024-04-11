using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CFShuffleSharp
{
    public class B
    {
        private TextReader Cin;
        TextWriter Cout;
        readonly int[] _bad = { ' ', '\r', '\n' };

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = Cin.Read())) != -1 && i != -1) ;
            sb.Append((char)i);

            if (i == -1)
                return null;
            while (Array.IndexOf(_bad, (i = Cin.Read())) == -1 && i != -1)
            {
                sb.Append((char)i);
            }
            return sb.ToString();
        }

        void Solve()
        {
            var s = NextToken();
            var k = int.Parse(NextToken());
            var a = new int[s.Length];
            for (var i = 0; i < s.Length; ++i)
            {
                a[i] = int.Parse(s[i].ToString());
            }
            var p = 0;
            for (p = 0; p < s.Length; ++p)
            {
                for (var i = 9; i >= 0; --i)
                {
                    while (p < s.Length)
                    {
                        if (a[p] >= i)
                            break;
                        var ind = -1;
                        for (var j = p + 1; j < s.Length; ++j)
                            if (a[j] == i)
                            {
                                ind = j;
                                break;
                            }
                        if (k >= ind - p && ind != -1)
                        {
                            k -= ind - p;
                            for (var j = ind - 1; j >= p; --j)
                            {
                                var t = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = t;
                            }
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            foreach (var i in a)
                Cout.Write(i);
        }
        void Run()
        {
            Cin = Console.In;
            Cout = Console.Out;
            Solve();
            Cout.Close();
            Cin.ReadLine();
            Cin.ReadLine();
        }

        public static void Main(string[] args)
        {
            new B().Run();
        }
    }
}