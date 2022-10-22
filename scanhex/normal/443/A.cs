using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CF253
{
    class A
    {
        readonly int[] _bad = { ' ', '\r', '\n', ',', '{', '}'};

        private string NextToken()
        {
            var sb = new StringBuilder();
            int i;

            while (Array.IndexOf(_bad, (i = Console.Read())) != -1)
            {
                if (i == -1) throw new IOException();
            }
            sb.Append((char)i);

            while (Array.IndexOf(_bad, (i = Console.Read())) == -1)
            {
                if (i == -1) throw new IOException();
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
            HashSet<char> hs = new HashSet<char>();
            try
            {
                while (true) hs.Add(NextToken()[0]);
            }
            catch { };
            Console.Write(hs.Count);
        }
        static void Main(string[] args)
        {
            new A().run();
        }
    }
}