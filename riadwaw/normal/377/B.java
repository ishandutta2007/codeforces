import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.io.Writer;
import java.util.StringTokenizer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author RiaD
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Reader in = new Reader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    class Student implements Comparable<Student> {
        long skill;
        long needs;
        int id;

        Student(long skill, long needs, int id) {
            this.skill = skill;
            this.needs = needs;
            this.id = id;
        }


        public int compareTo(Student o) {
            if(skill != o.skill)
                return Long.compare(o.skill, skill);
            return Integer.compare(id, o.id);
        }
    }
    public void solve(int testNumber, Reader in, OutputWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        long s = in.nextInt();
        long[] a = in.nextLongArray(m);
        long[] b = in.nextLongArray(n);
        long[] c = in.nextLongArray(n);

        ArrayList<Pair<Long, Integer>> bugs = new ArrayList<Pair<Long, Integer>>();
        ArrayList<Student> students = new ArrayList<Student>();
        for(int i = 0; i < n; ++i) {
            students.add(new Student(b[i], c[i], i));
        }
        for(int i = 0; i < m; ++i) {
            bugs.add(new Pair<Long, Integer>(a[i], i));
        }
        Collections.sort(bugs, Collections.reverseOrder());
        Collections.sort(students);
        int l = 0, r = m + 1;
        Comparator<Student> BY_NEEDS = new Comparator<Student>() {
            @Override
            public int compare(Student o1, Student o2) {
                if(o1.needs != o2.needs) {
                    return Long.compare(o1.needs, o2.needs);
                }
                return Integer.compare(o1.id, o2.id);
            }
        };
        int[] res = new int[m];
        while(r - l > 1) {
            int d = (l + r) / 2;
            int start = 0;
            TreeSet<Student> mayWork = new TreeSet<Student>(BY_NEEDS);

            boolean ok = true;
            long sum = 0;
            for(int i = 0; i < m; i += d) {
                for(; start != n && students.get(start).skill >= bugs.get(i).first; ++ start) {
                    mayWork.add(students.get(start));
                }

                if(mayWork.isEmpty()) {
                    ok = false;
                    break;
                }
                else {
                    Student cheap = mayWork.first();
                    mayWork.remove(cheap);
                    sum += cheap.needs;
                    for(int j = i; j < i + d && j < m; ++j) {
                        res[bugs.get(j).second] = cheap.id + 1;
                    }
                }

            }

            if(ok && sum <= s) {
                r = d;
            }
            else
                l = d;



        }

        if(r == m + 1) {
            out.println("NO");

        }
        else {
            out.println("YES");

            {
                int d = r;
                int start = 0;
                TreeSet<Student> mayWork = new TreeSet<Student>(BY_NEEDS);

                boolean ok = true;
                long sum = 0;
                for(int i = 0; i < m; i += d) {
                    for(; start != n && students.get(start).skill >= bugs.get(i).first; ++ start) {
                        mayWork.add(students.get(start));
                    }

                    if(mayWork.isEmpty()) {
                        ok = false;
                        break;
                    }
                    else {
                        Student cheap = mayWork.first();
                        mayWork.remove(cheap);
                        sum += cheap.needs;
                        for(int j = i; j < i + d && j < m; ++j) {
                            res[bugs.get(j).second] = cheap.id + 1;
                        }
                    }

                }

            }
            for(int i = 0; i < m; ++i) {
                out.print(res[i] + " ");
            }


        }
    }
}

class Reader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public Reader(BufferedReader reader) {
        this.reader = reader;
    }

    public Reader(InputStream stream) {
        this(new BufferedReader(new InputStreamReader(stream)));
    }

    public String nextString() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(readLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public long nextLong() {
        return Long.parseLong(nextString());
    }

    public long[] nextLongArray(int size) {
        long[] array = new long[size];
        for (int i = 0; i < size; ++i) {
            array[i] = nextLong();
        }
        return array;
    }

    private String readLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

class OutputWriter extends PrintWriter {

	public OutputWriter(OutputStream out) {
		super(out);
	}

	public OutputWriter(java.io.Writer writer){
		super(writer);
	}

	}

class Pair<F, S> implements Comparable<Pair<F, S>> {

    public F first;
    public S second;

    public Pair(F first, S second) {
        this.first = first;
        this.second = second;
    }

    public int compareTo(Pair<F, S> other) {
        int res = ((Comparable<F>) first).compareTo(other.first);
        if (res != 0) {
            return res;
        }
        return ((Comparable<S>) second).compareTo(other.second);
    }

    public String toString() {
        return "(" + first + "," + second + ")";
    }

    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }

        Pair pair = (Pair) o;

        if (first != null ? !first.equals(pair.first) : pair.first != null) {
            return false;
        }
        if (second != null ? !second.equals(pair.second) : pair.second != null) {
            return false;
        }

        return true;
    }

    public int hashCode() {
        int result = first != null ? first.hashCode() : 0;
        result = 31 * result + (second != null ? second.hashCode() : 0);
        return result;
    }
}