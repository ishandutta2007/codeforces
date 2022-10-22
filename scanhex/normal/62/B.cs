using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CFShuffleSharp
{
    public class B62
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

        int NextInt()
        {
            return int.Parse(NextToken());
        }

        void Solve()
        {
            var cont = new Dictionary<char, List<int>>();
            var n = NextInt();
            var k = NextInt();
            var s = NextToken();
            var potent = new string[n];
            for (var i = 0; i < n; ++i)
                potent[i] = NextToken();
            for (var i = 'a'; i <= 'z'; ++i)
                cont[i] = new List<int>();
            for (var i = 0; i < k; ++i)
                cont[s[i]].Add(i);
            for (var i = 0; i < n; ++i)
            {
                long F = 0;
                for (var j = 0; j < potent[i].Length; ++j)
                {
                    if (cont[potent[i][j]].Count == 0)
                    {
                        F += potent[i].Length;
                        continue;
                    }
                    var ind = cont[potent[i][j]].BinarySearch(j);
                    if (ind < 0)
                    {
                        var a = ~ind;
                        if (a == 0)
                        {
                            F += cont[potent[i][j]][a] - j;
                            continue;
                        }
                        if (a == cont[potent[i][j]].Count)
                        {
                            F += j - cont[potent[i][j]][a - 1];
                            continue;
                        }
                        var val = Math.Min(j - cont[potent[i][j]][a - 1], cont[potent[i][j]][a] - j); //cont[potent[i][j]][a] > j, cont[potent[i][j]][a - 1] < j
                        F += val;
                    }
                }
                Cout.WriteLine(F);
            }
        }

        public void Run()
        {
            Cin = Console.In;
            Cout = Console.Out;
            Solve();
            Cout.Close();
            Cin.ReadLine();
            Cin.ReadLine();
        }
        static void Main(string[] args)
        {
            new B62().Run();
        }
    }
}