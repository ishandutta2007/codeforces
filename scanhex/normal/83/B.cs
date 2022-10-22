using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CF
{
    class Event : IComparable<Event>
    {
        public int coord, creature;
        public Event(int coord, int creature)
        {
            this.coord = coord;
            this.creature = creature;
        }

        public int CompareTo(Event other)
        {
            int comp = coord.CompareTo(other.coord);
            if (comp != 0)
                return comp;
            return creature.CompareTo(other.creature);
        }
    }
    class B83
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

        long NextLong()
        {
            return long.Parse(NextToken());
        }

        void Run()
        {
            var n = NextInt();
            var k = NextLong();
            var a = new int[n];
            long sum = 0;
            for (var i = 0; i < n; ++i)
            {
                a[i] = NextInt();
                sum += a[i];
            }
            if (sum < k)
            {
                sw.Write(-1);
                return;
            }
            int L = 0, R = (int)1e9;
            while (R - L > 1)
            {
                int M = (R + L) / 2;
                sum = 0;
                for (var i = 0; i < n; ++i)
                    sum += Math.Min(a[i], M);
                if (sum > k)
                    R = M;
                else
                    L = M;
            }
            sum = 0;
            for (var i = 0; i < n; ++i)
                sum += Math.Min(a[i], L);
            for (int i = 0; i < n; ++i)
            {
                if (a[i] >= R)
                    ++sum;
                if (sum > k)
                {
                    for (int j = i; j < n; ++j)
                        if (a[j] > L)
                            sw.Write(j + 1 + " ");
                    for (int j = 0; j < i; ++j)
                        if (a[j] > R)
                            sw.Write(j + 1 + " ");
                    return;
                }
            }
        }

        static void Main(string[] args)
        {
            new B83().Run();
            Console.ReadLine();
            Console.ReadLine();
        }
    }
}